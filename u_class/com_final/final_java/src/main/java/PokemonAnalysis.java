import java.io.*;
import java.util.*;
import java.util.stream.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import javax.swing.*;
import javax.imageio.ImageIO;

import org.apache.commons.csv.*;
import org.apache.commons.math3.linear.*;
import org.apache.commons.math3.ml.clustering.*;
import org.apache.commons.math3.ml.distance.EuclideanDistance;
import org.apache.commons.math3.stat.correlation.Covariance;
import org.apache.commons.math3.stat.descriptive.DescriptiveStatistics;
import org.jfree.chart.*;
import org.jfree.chart.plot.*;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.chart.renderer.category.BarRenderer;

public class PokemonAnalysis {
    private static final String CSV_PATH = "pokedex.csv";
    private static final int OPTIMAL_K = 5;
    private static final String[] DROP_COLS = {
        "Unnamed: 0", "pokedex_number", "name", "japanese_name", "german_name",
        "egg_type_2", "type_number", "against_normal", "against_fire", "against_water",
        "against_electric", "against_grass", "against_ice", "against_fight", "against_poison",
        "against_ground", "against_flying", "against_psychic", "against_bug", "against_rock",
        "against_ghost", "against_dragon", "against_dark", "against_steel", "against_fairy", "type_2"
    };
    
    private static final Map<String, Integer> GROWTH_RATE_MAPPING = Map.of(
        "nan", 0, "Fluctuating", 1, "Slow", 2, "Medium Slow", 3,
        "Medium Fast", 4, "Fast", 5, "Erratic", 6
    );
    
    private List<Map<String, Object>> data;
    private double[][] processedData;
    private double[][] pcaData;
    private int[] clusters;
    private List<String> featureNames;
    
    public static void main(String[] args) {
        try {
            PokemonAnalysis analysis = new PokemonAnalysis();
            analysis.loadAndPreprocessData();
            analysis.performPCA();
            analysis.performClustering();
            analysis.visualizeResults();
            System.out.println("Analysis completed successfully!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void loadAndPreprocessData() throws IOException {
        System.out.println("Loading and preprocessing data...");
        
        // Load CSV data
        data = new ArrayList<>();
        try (Reader reader = new FileReader(CSV_PATH);
             CSVParser parser = CSVFormat.DEFAULT.withFirstRecordAsHeader().parse(reader)) {
            
            for (CSVRecord record : parser) {
                Map<String, Object> row = new HashMap<>();
                for (String header : record.getParser().getHeaderNames()) {
                    String value = record.get(header);
                    row.put(header, value != null && !value.trim().isEmpty() ? value : null);
                }
                
                // Filter out Mega Pokemon
                String name = (String) row.get("name");
                if (name == null || !name.startsWith("Mega")) {
                    data.add(row);
                }
            }
        }
        
        // Remove unwanted columns
        for (Map<String, Object> row : data) {
            for (String col : DROP_COLS) {
                row.remove(col);
            }
        }
        
        // Process growth_rate mapping
        for (Map<String, Object> row : data) {
            String growthRate = (String) row.get("growth_rate");
            if (growthRate == null) growthRate = "nan";
            row.put("growth_rate", GROWTH_RATE_MAPPING.getOrDefault(growthRate, 0));
        }
        
        // Process species column
        for (Map<String, Object> row : data) {
            String species = (String) row.get("species");
            if (species != null) {
                species = species.replaceAll("\\s*Pok[eé]mon$", "");
                row.put("species", species);
            }
        }
        
        // Count frequencies for categorical encoding
        Map<String, Integer> speciesCounts = getValueCounts("species");
        Map<String, Integer> ability1Counts = getValueCounts("ability_1");
        Map<String, Integer> ability2Counts = getValueCounts("ability_2");
        Map<String, Integer> abilityHiddenCounts = getValueCounts("ability_hidden");
        
        // Apply frequency encoding
        for (Map<String, Object> row : data) {
            row.put("species", speciesCounts.getOrDefault(row.get("species"), 0));
            row.put("ability_1", ability1Counts.getOrDefault(row.get("ability_1"), 0));
            row.put("ability_2", ability2Counts.getOrDefault(row.get("ability_2"), 0));
            row.put("ability_hidden", abilityHiddenCounts.getOrDefault(row.get("ability_hidden"), 0));
        }
        
        // Fill missing values
        fillMissingValues();
        
        // Convert to numerical matrix
        convertToNumericalMatrix();
        
        System.out.println("Data preprocessing completed. Shape: " + processedData.length + "x" + processedData[0].length);
    }
    
    private Map<String, Integer> getValueCounts(String column) {
        Map<String, Integer> counts = new HashMap<>();
        for (Map<String, Object> row : data) {
            String value = (String) row.get(column);
            if (value != null) {
                counts.put(value, counts.getOrDefault(value, 0) + 1);
            }
        }
        return counts;
    }
    
    private void fillMissingValues() {
        String[] fillNaCols = {"catch_rate", "base_friendship", "base_experience", 
                              "weight_kg", "ability_1", "egg_cycles"};
        
        for (String col : fillNaCols) {
            double mean = calculateMean(col);
            for (Map<String, Object> row : data) {
                if (row.get(col) == null) {
                    row.put(col, mean);
                }
            }
        }
        
        // Fill percentage_male with mode
        String mode = calculateMode("percentage_male");
        for (Map<String, Object> row : data) {
            if (row.get("percentage_male") == null) {
                row.put("percentage_male", mode);
            }
        }
    }
    
    private double calculateMean(String column) {
        return data.stream()
                .map(row -> row.get(column))
                .filter(Objects::nonNull)
                .mapToDouble(val -> {
                    try {
                        return Double.parseDouble(val.toString());
                    } catch (NumberFormatException e) {
                        return 0.0;
                    }
                })
                .average()
                .orElse(0.0);
    }
    
    private String calculateMode(String column) {
        return data.stream()
                .map(row -> (String) row.get(column))
                .filter(Objects::nonNull)
                .collect(Collectors.groupingBy(x -> x, Collectors.counting()))
                .entrySet().stream()
                .max(Map.Entry.comparingByValue())
                .map(Map.Entry::getKey)
                .orElse("");
    }
    
    private void convertToNumericalMatrix() {
        Set<String> allColumns = new HashSet<>();
        for (Map<String, Object> row : data) {
            allColumns.addAll(row.keySet());
        }
        
        // Separate numerical and categorical columns
        Set<String> categoricalCols = new HashSet<>();
        Set<String> numericalCols = new HashSet<>();
        
        for (String col : allColumns) {
            if (isNumericalColumn(col)) {
                numericalCols.add(col);
            } else {
                categoricalCols.add(col);
            }
        }
        
        // Create feature names list
        featureNames = new ArrayList<>(numericalCols);
        
        // Add one-hot encoded categorical features
        for (String col : categoricalCols) {
            Set<String> uniqueValues = data.stream()
                    .map(row -> (String) row.get(col))
                    .filter(Objects::nonNull)
                    .collect(Collectors.toSet());
            
            for (String value : uniqueValues) {
                featureNames.add(col + "_" + value);
            }
        }
        
        // Convert to matrix
        processedData = new double[data.size()][featureNames.size()];
        
        for (int i = 0; i < data.size(); i++) {
            Map<String, Object> row = data.get(i);
            int featureIndex = 0;
            
            // Add numerical features
            for (String col : numericalCols) {
                Object value = row.get(col);
                processedData[i][featureIndex++] = value != null ? 
                    Double.parseDouble(value.toString()) : 0.0;
            }
            
            // Add one-hot encoded categorical features
            for (String col : categoricalCols) {
                String value = (String) row.get(col);
                Set<String> uniqueValues = data.stream()
                        .map(r -> (String) r.get(col))
                        .filter(Objects::nonNull)
                        .collect(Collectors.toSet());
                
                for (String uniqueValue : uniqueValues) {
                    processedData[i][featureIndex++] = 
                        (value != null && value.equals(uniqueValue)) ? 1.0 : 0.0;
                }
            }
        }
        
        // Standardize numerical features
        standardizeFeatures();
    }
    
    private boolean isNumericalColumn(String column) {
        for (Map<String, Object> row : data) {
            Object value = row.get(column);
            if (value != null) {
                try {
                    Double.parseDouble(value.toString());
                } catch (NumberFormatException e) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private void standardizeFeatures() {
        int numFeatures = processedData[0].length;
        
        for (int j = 0; j < numFeatures; j++) {
            DescriptiveStatistics stats = new DescriptiveStatistics();
            for (int i = 0; i < processedData.length; i++) {
                stats.addValue(processedData[i][j]);
            }
            
            double mean = stats.getMean();
            double std = stats.getStandardDeviation();
            
            if (std > 0) {
                for (int i = 0; i < processedData.length; i++) {
                    processedData[i][j] = (processedData[i][j] - mean) / std;
                }
            }
        }
    }
    
    public void performPCA() {
        System.out.println("Performing PCA...");
        
        // Calculate covariance matrix
        RealMatrix dataMatrix = MatrixUtils.createRealMatrix(processedData);
        Covariance covariance = new Covariance(dataMatrix);
        RealMatrix covarianceMatrix = covariance.getCovarianceMatrix();
        
        // Eigenvalue decomposition
        EigenDecomposition eigenDecomp = new EigenDecomposition(covarianceMatrix);
        double[] eigenValues = eigenDecomp.getRealEigenvalues();
        RealMatrix eigenVectors = eigenDecomp.getV();
        
        // Sort eigenvalues and eigenvectors in descending order
        Integer[] indices = IntStream.range(0, eigenValues.length)
                .boxed().toArray(Integer[]::new);
        Arrays.sort(indices, (i, j) -> Double.compare(eigenValues[j], eigenValues[i]));
        
        // Calculate cumulative variance explained
        double totalVariance = Arrays.stream(eigenValues).sum();
        double cumulativeVariance = 0;
        int numComponents = 0;
        
        for (int i : indices) {
            cumulativeVariance += eigenValues[i];
            numComponents++;
            if (cumulativeVariance / totalVariance >= 0.9) {
                break;
            }
        }
        
        // Create transformation matrix
        double[][] transformationMatrix = new double[numComponents][processedData[0].length];
        for (int i = 0; i < numComponents; i++) {
            for (int j = 0; j < processedData[0].length; j++) {
                transformationMatrix[i][j] = eigenVectors.getEntry(j, indices[i]);
            }
        }
        
        // Transform data
        pcaData = new double[processedData.length][numComponents];
        for (int i = 0; i < processedData.length; i++) {
            for (int j = 0; j < numComponents; j++) {
                double sum = 0;
                for (int k = 0; k < processedData[0].length; k++) {
                    sum += processedData[i][k] * transformationMatrix[j][k];
                }
                pcaData[i][j] = sum;
            }
        }
        
        System.out.println("PCA completed. Reduced to " + numComponents + " components.");
        System.out.println("Variance explained: " + (cumulativeVariance / totalVariance * 100) + "%");
    }
    
    public void performClustering() {
        System.out.println("Performing K-means clustering...");
        
        // Find optimal k using elbow method
        double[] distortions = new double[29];
        for (int k = 1; k <= 29; k++) {
            KMeansPlusPlusClusterer<DoublePoint> clusterer = 
                new KMeansPlusPlusClusterer<>(k, 100, new EuclideanDistance());
            
            List<DoublePoint> points = Arrays.stream(pcaData)
                    .map(DoublePoint::new)
                    .collect(Collectors.toList());
            
            List<CentroidCluster<DoublePoint>> clusterResults = clusterer.cluster(points);
            
            double sse = 0;
            for (CentroidCluster<DoublePoint> cluster : clusterResults) {
                Clusterable centroid = cluster.getCenter();
                for (DoublePoint point : cluster.getPoints()) {
                    sse += Math.pow(new EuclideanDistance().compute(
                        point.getPoint(), centroid.getPoint()), 2);
                }
            }
            distortions[k-1] = sse;
        }
        
        // Perform final clustering with optimal k
        KMeansPlusPlusClusterer<DoublePoint> finalClusterer = 
            new KMeansPlusPlusClusterer<>(OPTIMAL_K, 100, new EuclideanDistance());
        
        List<DoublePoint> points = Arrays.stream(pcaData)
                .map(DoublePoint::new)
                .collect(Collectors.toList());
        
        List<CentroidCluster<DoublePoint>> clusterResults = finalClusterer.cluster(points);
        
        // Assign cluster labels
        clusters = new int[pcaData.length];
        int pointIndex = 0;
        for (int clusterIndex = 0; clusterIndex < clusterResults.size(); clusterIndex++) {
            CentroidCluster<DoublePoint> cluster = clusterResults.get(clusterIndex);
            for (DoublePoint point : cluster.getPoints()) {
                // Find the original index of this point
                for (int i = 0; i < pcaData.length; i++) {
                    if (Arrays.equals(pcaData[i], point.getPoint())) {
                        clusters[i] = clusterIndex;
                        break;
                    }
                }
            }
        }
        
        System.out.println("Clustering completed with k=" + OPTIMAL_K);
    }
    
    public void visualizeResults() {
        System.out.println("Creating visualizations...");
        
        // Create elbow plot
        createElbowPlot();
        
        // Create cluster type distribution plots
        createClusterTypeDistribution();
        
        // Create heatmap
        createPCAHeatmap();
        
        System.out.println("Visualization completed!");
    }
    
    private void createElbowPlot() {
        // Calculate distortions for elbow plot
        double[] distortions = new double[29];
        for (int k = 1; k <= 29; k++) {
            KMeansPlusPlusClusterer<DoublePoint> clusterer = 
                new KMeansPlusPlusClusterer<>(k, 100, new EuclideanDistance());
            
            List<DoublePoint> points = Arrays.stream(pcaData)
                    .map(DoublePoint::new)
                    .collect(Collectors.toList());
            
            List<CentroidCluster<DoublePoint>> clusterResults = clusterer.cluster(points);
            
            double sse = 0;
            for (CentroidCluster<DoublePoint> cluster : clusterResults) {
                Clusterable centroid = cluster.getCenter();
                for (DoublePoint point : cluster.getPoints()) {
                    sse += Math.pow(new EuclideanDistance().compute(
                        point.getPoint(), centroid.getPoint()), 2);
                }
            }
            distortions[k-1] = sse;
        }
        
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        for (int i = 0; i < distortions.length; i++) {
            dataset.addValue(distortions[i], "SSE", String.valueOf(i + 1));
        }
        
        JFreeChart chart = ChartFactory.createLineChart(
            "Elbow Method For Optimal k",
            "Number of clusters (k)",
            "SSE",
            dataset,
            PlotOrientation.VERTICAL,
            false, true, false
        );
        
        saveChart(chart, "elbow_plot.png", 800, 600);
    }
    
    private void createClusterTypeDistribution() {
        // Get type_1 data
        List<String> type1Data = new ArrayList<>();
        for (Map<String, Object> row : data) {
            type1Data.add((String) row.get("type_1"));
        }
        
        // Count types per cluster
        Map<Integer, Map<String, Integer>> clusterTypeCounts = new HashMap<>();
        for (int i = 0; i < clusters.length; i++) {
            int cluster = clusters[i];
            String type = type1Data.get(i);
            
            clusterTypeCounts.computeIfAbsent(cluster, k -> new HashMap<>())
                    .merge(type, 1, Integer::sum);
        }
        
        // Create bar charts for each cluster
        for (int cluster = 0; cluster < OPTIMAL_K; cluster++) {
            DefaultCategoryDataset dataset = new DefaultCategoryDataset();
            Map<String, Integer> typeCounts = clusterTypeCounts.getOrDefault(cluster, new HashMap<>());
            
            for (Map.Entry<String, Integer> entry : typeCounts.entrySet()) {
                dataset.addValue(entry.getValue(), "Count", entry.getKey());
            }
            
            JFreeChart chart = ChartFactory.createBarChart(
                "Type Distribution in Cluster " + cluster,
                "Type",
                "Count",
                dataset,
                PlotOrientation.VERTICAL,
                false, true, false
            );
            
            CategoryPlot plot = chart.getCategoryPlot();
            BarRenderer renderer = (BarRenderer) plot.getRenderer();
            renderer.setDefaultPaint(Color.CYAN);
            
            saveChart(chart, "cluster_" + cluster + "_distribution.png", 800, 600);
        }
    }
    
    private void createPCAHeatmap() {
        // Calculate mean PCA values for each type
        Map<String, double[]> typePCAMeans = new HashMap<>();
        Map<String, Integer> typeCounts = new HashMap<>();
        
        List<String> type1Data = new ArrayList<>();
        for (Map<String, Object> row : data) {
            type1Data.add((String) row.get("type_1"));
        }
        
        for (int i = 0; i < Math.min(pcaData.length, type1Data.size()); i++) {
            String type = type1Data.get(i);
            if (type != null) {
                double[] currentMeans = typePCAMeans.getOrDefault(type, new double[3]);
                int count = typeCounts.getOrDefault(type, 0);
                
                for (int j = 0; j < Math.min(3, pcaData[i].length); j++) {
                    currentMeans[j] = (currentMeans[j] * count + pcaData[i][j]) / (count + 1);
                }
                
                typePCAMeans.put(type, currentMeans);
                typeCounts.put(type, count + 1);
            }
        }
        
        // Create heatmap visualization using a simple approach
        createSimpleHeatmap(typePCAMeans);
    }
    
    private void createSimpleHeatmap(Map<String, double[]> typePCAMeans) {
        int width = 400;
        int height = typePCAMeans.size() * 30 + 100;
        
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics2D g2d = image.createGraphics();
        g2d.setColor(Color.WHITE);
        g2d.fillRect(0, 0, width, height);
        
        g2d.setColor(Color.BLACK);
        g2d.setFont(new Font("Arial", Font.BOLD, 14));
        g2d.drawString("Average PC Values by Type", 10, 20);
        g2d.drawString("PC1", 150, 50);
        g2d.drawString("PC2", 200, 50);
        g2d.drawString("PC3", 250, 50);
        
        int y = 70;
        for (Map.Entry<String, double[]> entry : typePCAMeans.entrySet()) {
            g2d.drawString(entry.getKey(), 10, y);
            double[] means = entry.getValue();
            
            for (int i = 0; i < 3 && i < means.length; i++) {
                double value = means[i];
                int intensity = (int) Math.min(255, Math.max(0, 128 + value * 50));
                Color cellColor = new Color(intensity, intensity, 255 - intensity);
                g2d.setColor(cellColor);
                g2d.fillRect(140 + i * 50, y - 15, 40, 20);
                
                g2d.setColor(Color.BLACK);
                g2d.drawRect(140 + i * 50, y - 15, 40, 20);
                g2d.drawString(String.format("%.2f", value), 145 + i * 50, y);
            }
            y += 30;
        }
        
        g2d.dispose();
        
        try {
            ImageIO.write(image, "PNG", new File("pca_heatmap.png"));
            System.out.println("Heatmap saved as pca_heatmap.png");
        } catch (IOException e) {
            System.err.println("Error saving heatmap: " + e.getMessage());
        }
    }
    
    private void saveChart(JFreeChart chart, String filename, int width, int height) {
        try {
            ChartUtils.saveChartAsPNG(new File(filename), chart, width, height);
            System.out.println("Chart saved as " + filename);
        } catch (IOException e) {
            System.err.println("Error saving chart: " + e.getMessage());
        }
    }
}