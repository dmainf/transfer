import re
import matplotlib.pyplot as plt

def create_pca_charts(file_path):
    with open(file_path, 'r') as f:
        text = f.read()

    # Split the text by principal components
    components = re.split(r'Principal Component \d+:', text)[1:]

    for i, component in enumerate(components):
        # Parse the feature and weight for each component
        features = []
        weights = []
        for line in component.strip().split('\n'):
            match = re.match(r'\s*(.*?):\s*(-?\d+\.\d+)', line)
            if match:
                weight = float(match.group(2))
                if abs(weight) >= 0.3:
                    features.append(match.group(1).strip())
                    weights.append(weight)

        # Create a bar chart for the component
        plt.figure(figsize=(10, 6))
        plt.bar(features, weights)
        plt.xlabel('Features')
        plt.ylabel('Weights')
        plt.title(f'Principal Component {i+1}')
        plt.xticks(rotation=90)
        plt.tight_layout()
        plt.savefig(f'principal_component_{i+1}.png')
        plt.close()

if __name__ == '__main__':
    create_pca_charts('/home/dmainf/pca.txt')