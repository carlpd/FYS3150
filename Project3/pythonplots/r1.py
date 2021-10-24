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
q=1.0
Tesla=9.64852558e1
Volt=9.64852558e7
V0=10.0*Volt
m=20.0
d=1e4
wz=np.sqrt(2*q*V0/(m*d**2))
print("Analytisk w_z=", wz)
print("Perioder på 100 mikrsekunder =", wz*100)
t, vz=np.loadtxt("../Txtfiler/v1.txt", unpack=True)
plt.plot(t,vz)
plt.show()
plt.plot(x,y)
plt.plot(x[0],y[0], "ro", label="start")
plt.savefig("1partikkelEuler.pdf")
plt.show()
