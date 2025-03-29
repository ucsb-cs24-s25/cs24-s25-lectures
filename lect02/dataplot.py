# Install the matplotlib and numpy packages
# python3 -m pip install matplotlib numpy 
import matplotlib.pyplot as plt
import numpy as np
import math

# Read data from file
n = []
time = []
with open('data.txt', 'r') as fp:
    fp.readline()  # Skip header: "n    Time (ms)"
    for line in fp:
        data = line.split()  # Split on whitespace (handles spaces/tabs)
        n.append(int(data[0]))
        time.append(float(data[1]))

# Calculate log2 of time
log2_time = [math.log2(x) for x in time]

# Fit a line (linear regression: log2_time = m * n + b)
m, b = np.polyfit(n, log2_time, 1)  # Degree 1 = linear fit
fit_line = [m * x + b for x in n]   # y = mx + b for each n

# Create scatterplot with fitted line
plt.scatter(n, log2_time, color='blue', label='Data')  # Scatter points
plt.plot(n, fit_line, color='red', label=f'Fit: slope = {m:.2f}')  # Fitted line
plt.xlabel('Input Size (n)')
plt.ylabel('log₂(T(n))')
plt.title('Log₂ of Running Time vs. Input Size')
plt.grid(True)
plt.legend()
plt.show()

# Print slope for reference
print(f"Slope of the fitted line: {m:.2f}")
print(f"Base b = 2^slope ≈ {2**m:.2f}")