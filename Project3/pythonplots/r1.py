import numpy as np
import matplotlib.pyplot as plt

t, x, y, z=np.loadtxt("../Txtfiler/r1.txt", unpack=True)

plt.title("Posisjon i x-retning")
plt.xlabel("Tid i mikrosekunder")
plt.ylabel("Posisjon i x-retning i mikrometer")
plt.plot(t,x)
plt.savefig("r1x.pdf")
plt.show()
plt.title("Posisjon i y-retning")
plt.xlabel("Tid i mikrosekunder")
plt.ylabel("Posisjon i y-retning i mikrometer")
plt.plot(t,y)
plt.savefig("r1y.pdf")
plt.show()
plt.title("Posisjon i z-retning")
plt.xlabel("Tid i mikrosekunder")
plt.ylabel("Posisjon i z-retning i mikrometer")
plt.plot(t,z)
plt.savefig("r1z.pdf")
plt.show()
q=1.0
Tesla=9.64852558e1
Volt=9.64852558e7
V0=10.0*Volt
m=20.0
d=1e4
wz=np.sqrt(2*q*V0/(m*d**2))
print("Analytisk w_z=", wz)
f=wz/(2*np.pi)
print("Antall topppunkter er", f*100)
t, vz=np.loadtxt("../Txtfiler/v1.txt", unpack=True)
plt.title("Hastighet i z-retning")
plt.xlabel("Tid i mikrosekunder")
plt.ylabel("Hastighet i z-retning i m/s")
plt.plot(t,vz)
plt.savefig("vz.pdf")
plt.show()
"""
plt.plot(x,y)
plt.plot(x[0],y[0], "ro", label="start")
plt.savefig("1partikkelEuler.pdf")
plt.show()
"""
