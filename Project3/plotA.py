import numpy as np
import matplotlib.pyplot as plt

q = 1
V0 = 9.65e8
m = 1
B0 = 9.65e1
z0 = 1
x0 = 1
y0 = 1
v0 = 1

t = np.linspace(0, 1, 1000) # Bare bytt ut

d = 1e4 #sqrt(z0**2 + (x0**2 + y0**2 + z0**2)/2)
oz = np.sqrt(2*abs(q)*V0/(m*d**2))
o0 = abs(q)*B0/m
oP = (o0+np.sqrt(o0**2-2*oz**2))/2
oM = (o0-np.sqrt(o0**2-2*oz**2))/2
AP = (v0 + oM*x0)/(oM-oP)
AM = (v0 + oP*x0)/(oM-oP)

z = z0/2*np.exp(-(1j)*oz*t) + z0/2*np.exp(-(1j)*oz*t)
f = AP*np.exp(-(1j)*oP*t) + AM*np.exp(-(1j)*oM*t)
x = np.real(f)
y = np.imag(f)

plt.plot(x, y)
plt.show()
