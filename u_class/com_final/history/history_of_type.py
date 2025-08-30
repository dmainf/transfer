import matplotlib.pyplot as plt

# Data
generations = ["1", "2", "3–5", "6", "7–8", "9"]
type_counts = [15, 17, 17, 18, 18, 19]

# Plot the graph
plt.figure(figsize=(8, 5))
plt.plot(generations, type_counts, marker='*', color='darkblue', linewidth=2)
plt.title("Number of Pokémon Types by Generation", fontsize=14)
plt.xlabel("Generation", fontsize=12)
plt.ylabel("Number of Types", fontsize=12)
plt.ylim(14, 20)
plt.grid(True, linestyle='--', alpha=0.5)

# Show data point labels
for gen, count in zip(generations, type_counts):
    plt.text(gen, count + 0.2, str(count), ha='center', fontsize=10)

plt.tight_layout()
plt.show()