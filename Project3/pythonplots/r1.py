import numpy as np
import matplotlib.pyplot as plt

t, x, y, z=np.loadtxt("../Txtfiler/r1.txt", unpack=True)
plt.subplot(1,3,1)
plt.plot(t,x)
plt.subplot(1,3,2)
plt.plot(t,y)
plt.subplot(1,3,3)
plt.plot(t,z)
plt.show()
t, wz=np.loadtxt("../Txtfiler/wz1.txt", unpack=True)
plt.plot(t,wz)
plt.show()
