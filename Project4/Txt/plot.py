import numpy as np
import matplotlib.pyplot as plt

s, e, e2, m, m2 = np.loadtxt('Chain.txt', unpack=True)
"""L=20
for i in [e, e2, m, m2]:
    plt.plot(s, i)
    plt.show()
"""

plt.plot(s, e/400)
plt.show()
