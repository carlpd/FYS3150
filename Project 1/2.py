import numpy as np
import matplotlib.pyplot as plt

col1, col2 = np.loadtxt("2tekst.txt", unpack=True)

plt.plot(col1, col2)
plt.xlabel("x")
plt.ylabel("u(x)")
plt.show()
