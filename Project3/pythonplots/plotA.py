import numpy as np
import matplotlib.pyplot as plt

Volt=9.64852558e7;
Tesla=9.64852558e1;
ke=1.38935333e5;
q = 1
V0=10.0*Volt;
B0=1.0*Tesla;
d=10**4
#V0 = 9.65e8
m = 20
#B0 = 9.65e1
z0 = 1
x0 = 1
y0 = 0
v0 = 1

t = np.linspace(0, 100, 100000) # Bare bytt ut
wz=2*q*v0/(m*d**2)
d = 1e4 #sqrt(z0**2 + (x0**2 + y0**2 + z0**2)/2)
oz = np.sqrt(2*abs(q)*V0/(m*d**2))
o0 = abs(q)*B0/m
oP = (o0+np.sqrt(o0**2-2*oz**2))/2
oM = (o0-np.sqrt(o0**2-2*oz**2))/2
print(f'oz = {oz}')
print(f'om = {oM}')
print(f'op = {oP}')
AP = (v0 + oM*x0)/(oM-oP)
AM = (-1)*(v0 + oP*x0)/(oM-oP)

z = z0*np.cos(wz*t)#z0/2*np.exp(-(1j)*oz*t) + z0/2*np.exp(-(1j)*oz*t)
f = AP*np.exp(-(1j)*oP*t) + AM*np.exp(-(1j)*oM*t)
x=AP*np.cos(oP*t)+AM*np.cos(oM*t)
y=(-AP)*np.sin(oP*t)-AM*np.sin(oM*t)
#x = np.real(f)
#y = np.imag(f)
tn, xn, yn, zn=np.loadtxt("../Txtfiler/r1.txt", unpack=True)
plt.plot(x, y, label="analytisk")
plt.plot(x[0], y[0], "bo")
plt.plot(xn,yn, label="numerisk")
plt.plot(xn[0],yn[0], "ro")
plt.legend()
#plt.savefig("1partikkelEuler.pdf")
plt.show()

plt.show()


from mpl_toolkits import mplot3d

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.set_xlabel('x [μm]')
ax.set_ylabel('y [μm]')
#ax.set_zlabel('z [μm]')
ax.plot(x, y, z)
plt.show()
