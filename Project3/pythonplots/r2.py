import numpy as np
import matplotlib.pyplot as plt

t, x1, y1,z1, x2, y2, z2=np.loadtxt("../Txtfiler/r2noint.txt", unpack=True)
plt.plot(x1,y1)
plt.plot(x2, y2)
plt.show()
t, x1, y1, z1 , x2, y2, z2=np.loadtxt("../Txtfiler/r2int.txt", unpack=True)
plt.plot(x1,y1)
plt.plot(x2, y2)
plt.show()
