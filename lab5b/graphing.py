import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv('search_timing.csv')

# Set up the figure and subplots
plt.figure(figsize=(15, 5))
plt.suptitle('Search Algorithm Performance Analysis', fontsize=16)

# Graph 1: Present Items
plt.subplot(1, 3, 1)
plt.plot(df['Size'], df['HT50_Present'], 'b-o', label='HT 50%')
plt.plot(df['Size'], df['HT95_Present'], 'r-o', label='HT 95%')
plt.plot(df['Size'], df['Seq_Present'], 'g-o', label='Sequential')
plt.plot(df['Size'], df['Bin_Present'], 'y-o', label='Binary')
plt.yscale('log')
plt.title('Search Time for Present Items (Log Scale)')
plt.xlabel('List Size')
plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True)

# Graph 2: Non-Present Items
plt.subplot(1, 3, 2)
plt.plot(df['Size'], df['HT50_NotPresent'], 'b-o', label='HT 50%')
plt.plot(df['Size'], df['HT95_NotPresent'], 'r-o', label='HT 95%')
plt.plot(df['Size'], df['Seq_NotPresent'], 'g-o', label='Sequential')
plt.plot(df['Size'], df['Bin_NotPresent'], 'y-o', label='Binary')
plt.yscale('log')
plt.title('Search Time for Non-Present Items (Log Scale)')
plt.xlabel('List Size')
plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True)

# Graph 3: All Hash Table Timings
plt.subplot(1, 3, 3)
plt.plot(df['Size'], df['HT50_Present'], 'b-o', label='HT 50% Present')
plt.plot(df['Size'], df['HT50_NotPresent'], 'b--o', label='HT 50% Not Present')
plt.plot(df['Size'], df['HT95_Present'], 'r-o', label='HT 95% Present')
plt.plot(df['Size'], df['HT95_NotPresent'], 'r--o', label='HT 95% Not Present')
plt.yscale('log')
plt.title('Hash Table Performance Comparison (Log Scale)')
plt.xlabel('List Size')
plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True)

# Adjust layout and save
plt.tight_layout(rect=(0, 0, 1, 0.95))  # Adjust for suptitle
plt.savefig('search_performance.png', dpi=300, bbox_inches='tight')
plt.savefig('search_performance.pdf', dpi=300, bbox_inches='tight')
plt.savefig('search_performance.svg', dpi=300, bbox_inches='tight')
plt.show()
