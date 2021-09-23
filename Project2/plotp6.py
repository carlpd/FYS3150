import numpy as np
import matplotlib.pyplot as plt

n, i = np.loadtxt("Data/Iterations.txt", unpack=True)
x = np.linspace(0, 100, 10000)
p2 = x**2.15
p3 = x**3
ax = plt.axes(xlabel='n', ylabel='Iterations', title='Iterations for nxn matrix')
ax.plot(n, i, label='Data')
ax.plot(x, p2, "--", label='x^2.15')
plt.legend()
plt.savefig('Images/Iterations.pdf')
plt.show()
