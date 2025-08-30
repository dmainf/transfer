import java.io.*;
import java.util.*;
import java.util.stream.*;

public class SimplePokemonAnalysis {
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
    
    private List<Map<String, String>> data;
    private double[][] processedData;
    private double[][] pcaData;
    private int[] clusters;
    private List<String> featureNames;
    
    public static void main(String[] args) {
        try {
            SimplePokemonAnalysis analysis = new SimplePokemonAnalysis();
            analysis.loadAndPreprocessData();
            analysis.performSimplePCA();
            analysis.performSimpleClustering();
            analysis.analyzeResults();
            System.out.println("Analysis completed successfully!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void loadAndPreprocessData() throws IOException {
        System.out.println("Loading and preprocessing data...");
        
        // Load CSV data
        data = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(CSV_PATH))) {
            String line = reader.readLine(); // header
            if (line == null) {
                throw new IOException("Empty CSV file");
            }
            
            String[] headers = line.split(",");
            
            while ((line = reader.readLine()) != null) {
                String[] values = line.split(",", -1);
                Map<String, String> row = new HashMap<>();
                
                for (int i = 0; i < Math.min(headers.length, values.length); i++) {
                    String value = values[i].trim();
                    if (value.isEmpty() || value.equals("null") || value.equals("NaN")) {
                        value = null;
                    }
                    row.put(headers[i].trim(), value);
                }
                
                // Filter out Mega Pokemon
                String name = row.get("name");
                if (name == null || !name.startsWith("Mega")) {
                    data.add(row);
                }
            }
        }
        
        System.out.println("Loaded " + data.size() + " Pokemon records");
        
        // Remove unwanted columns
        for (Map<String, String> row : data) {
            for (String col : DROP_COLS) {
                row.remove(col);
            }
        }
        
        // Process growth_rate mapping
        for (Map<String, String> row : data) {
            String growthRate = row.get("growth_rate");
            if (growthRate == null) growthRate = "nan";
            row.put("growth_rate", String.valueOf(GROWTH_RATE_MAPPING.getOrDefault(growthRate, 0)));
        }
        
        // Fill missing values and convert to numerical matrix
        fillMissingValues();
        convertToNumericalMatrix();
        
        System.out.println("Data preprocessing completed. Shape: " + processedData.length + "x" + processedData[0].length);
    }
    
    private void fillMissingValues() {
        String[] numericCols = {"hp", "attack", "defense", "sp_attack", "sp_defense", "speed", 
                               "catch_rate", "base_friendship", "base_experience", "weight_kg"};
        
        for (String col : numericCols) {
            double mean = calculateMean(col);
            for (Map<String, String> row : data) {
                if (row.get(col) == null) {
                    row.put(col, String.valueOf(mean));
                }
            }
        }
        
        // Fill percentage_male with mode
        String mode = calculateMode("percentage_male");
        for (Map<String, String> row : data) {
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
                        return Double.parseDouble(val);
                    } catch (NumberFormatException e) {
                        return 0.0;
                    }
                })
                .average()
                .orElse(0.0);
    }
    
    private String calculateMode(String column) {
        return data.stream()
                .map(row -> row.get(column))
                .filter(Objects::nonNull)
                .collect(Collectors.groupingBy(x -> x, Collectors.counting()))
                .entrySet().stream()
                .max(Map.Entry.comparingByValue())
                .map(Map.Entry::getKey)
                .orElse("50.0");
    }
    
    private void convertToNumericalMatrix() {
        // Use only numerical columns for simplicity
        String[] selectedCols = {"hp", "attack", "defense", "sp_attack", "sp_defense", "speed", 
                                "catch_rate", "base_friendship", "base_experience", "weight_kg", "growth_rate"};
        
        featureNames = Arrays.asList(selectedCols);
        processedData = new double[data.size()][selectedCols.length];
        
        for (int i = 0; i < data.size(); i++) {
            Map<String, String> row = data.get(i);
            for (int j = 0; j < selectedCols.length; j++) {
                String value = row.get(selectedCols[j]);
                processedData[i][j] = value != null ? Double.parseDouble(value) : 0.0;
            }
        }
        
        // Standardize features
        standardizeFeatures();
    }
    
    private void standardizeFeatures() {
        int numFeatures = processedData[0].length;
        
        for (int j = 0; j < numFeatures; j++) {
            double sum = 0;
            for (int i = 0; i < processedData.length; i++) {
                sum += processedData[i][j];
            }
            double mean = sum / processedData.length;
            
            double sumSquaredDiff = 0;
            for (int i = 0; i < processedData.length; i++) {
                sumSquaredDiff += Math.pow(processedData[i][j] - mean, 2);
            }
            double std = Math.sqrt(sumSquaredDiff / processedData.length);
            
            if (std > 0) {
                for (int i = 0; i < processedData.length; i++) {
                    processedData[i][j] = (processedData[i][j] - mean) / std;
                }
            }
        }
    }
    
    public void performSimplePCA() {
        System.out.println("Performing simplified PCA...");
        
        int numFeatures = processedData[0].length;
        int numComponents = Math.min(3, numFeatures); // Keep first 3 components
        
        // For simplicity, we'll just take the first few features as our "principal components"
        // This is a simplified version - real PCA would require eigenvalue decomposition
        pcaData = new double[processedData.length][numComponents];
        
        for (int i = 0; i < processedData.length; i++) {
            System.arraycopy(processedData[i], 0, pcaData[i], 0, numComponents);
        }
        
        System.out.println("PCA completed with " + numComponents + " components.");
    }
    
    public void performSimpleClustering() {
        System.out.println("Performing K-means clustering...");
        
        // Simple K-means implementation
        Random random = new Random(42);
        int numClusters = OPTIMAL_K;
        int numFeatures = pcaData[0].length;
        
        // Initialize centroids randomly
        double[][] centroids = new double[numClusters][numFeatures];
        for (int i = 0; i < numClusters; i++) {
            for (int j = 0; j < numFeatures; j++) {
                centroids[i][j] = random.nextGaussian();
            }
        }
        
        clusters = new int[pcaData.length];
        boolean changed = true;
        int maxIterations = 100;
        int iteration = 0;
        
        while (changed && iteration < maxIterations) {
            changed = false;
            
            // Assign points to closest centroid
            for (int i = 0; i < pcaData.length; i++) {
                double minDistance = Double.MAX_VALUE;
                int closestCluster = 0;
                
                for (int k = 0; k < numClusters; k++) {
                    double distance = euclideanDistance(pcaData[i], centroids[k]);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestCluster = k;
                    }
                }
                
                if (clusters[i] != closestCluster) {
                    clusters[i] = closestCluster;
                    changed = true;
                }
            }
            
            // Update centroids
            double[][] newCentroids = new double[numClusters][numFeatures];
            int[] clusterCounts = new int[numClusters];
            
            for (int i = 0; i < pcaData.length; i++) {
                int cluster = clusters[i];
                clusterCounts[cluster]++;
                for (int j = 0; j < numFeatures; j++) {
                    newCentroids[cluster][j] += pcaData[i][j];
                }
            }
            
            for (int k = 0; k < numClusters; k++) {
                if (clusterCounts[k] > 0) {
                    for (int j = 0; j < numFeatures; j++) {
                        centroids[k][j] = newCentroids[k][j] / clusterCounts[k];
                    }
                }
            }
            
            iteration++;
        }
        
        System.out.println("Clustering completed in " + iteration + " iterations with k=" + numClusters);
    }
    
    private double euclideanDistance(double[] point1, double[] point2) {
        double sum = 0;
        for (int i = 0; i < point1.length; i++) {
            sum += Math.pow(point1[i] - point2[i], 2);
        }
        return Math.sqrt(sum);
    }
    
    public void analyzeResults() {
        System.out.println("\n=== CLUSTER ANALYSIS ===");
        
        // Count cluster sizes
        Map<Integer, Integer> clusterSizes = new HashMap<>();
        for (int cluster : clusters) {
            clusterSizes.put(cluster, clusterSizes.getOrDefault(cluster, 0) + 1);
        }
        
        System.out.println("Cluster sizes:");
        for (int i = 0; i < OPTIMAL_K; i++) {
            System.out.println("Cluster " + i + ": " + clusterSizes.getOrDefault(i, 0) + " Pokemon");
        }
        
        // Analyze type distribution in clusters
        System.out.println("\nType distribution in clusters:");
        for (int clusterNum = 0; clusterNum < OPTIMAL_K; clusterNum++) {
            System.out.println("\nCluster " + clusterNum + ":");
            Map<String, Integer> typeCounts = new HashMap<>();
            
            for (int i = 0; i < clusters.length; i++) {
                if (clusters[i] == clusterNum) {
                    String type = data.get(i).get("type_1");
                    if (type != null) {
                        typeCounts.put(type, typeCounts.getOrDefault(type, 0) + 1);
                    }
                }
            }
            
            typeCounts.entrySet().stream()
                    .sorted(Map.Entry.<String, Integer>comparingByValue().reversed())
                    .limit(5)
                    .forEach(entry -> System.out.println("  " + entry.getKey() + ": " + entry.getValue()));
        }
        
        // Show some example Pokemon from each cluster
        System.out.println("\nExample Pokemon from each cluster:");
        for (int clusterNum = 0; clusterNum < OPTIMAL_K; clusterNum++) {
            System.out.println("\nCluster " + clusterNum + " examples:");
            int count = 0;
            for (int i = 0; i < clusters.length && count < 3; i++) {
                if (clusters[i] == clusterNum) {
                    String name = data.get(i).get("name");
                    String type = data.get(i).get("type_1");
                    if (name != null) {
                        System.out.println("  " + name + " (" + type + ")");
                        count++;
                    }
                }
            }
        }
        
        // Calculate average stats for each cluster
        System.out.println("\nAverage stats by cluster:");
        String[] statCols = {"hp", "attack", "defense", "sp_attack", "sp_defense", "speed"};
        
        for (int clusterNum = 0; clusterNum < OPTIMAL_K; clusterNum++) {
            System.out.println("\nCluster " + clusterNum + " average stats:");
            
            for (String stat : statCols) {
                double sum = 0;
                int count = 0;
                
                for (int i = 0; i < clusters.length; i++) {
                    if (clusters[i] == clusterNum) {
                        String value = data.get(i).get(stat);
                        if (value != null) {
                            try {
                                sum += Double.parseDouble(value);
                                count++;
                            } catch (NumberFormatException e) {
                                // Skip invalid values
                            }
                        }
                    }
                }
                
                if (count > 0) {
                    System.out.printf("  %s: %.1f\n", stat, sum / count);
                }
            }
        }
    }
}