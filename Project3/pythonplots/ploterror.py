import matplotlib.pyplot as plt
import numpy as np

dtmax=0
dtmin=5 #En under minste
maxEu=np.zeros(dtmin)
maxRK=np.zeros(dtmin)
"""
plt.title("Absolutt feil med Euler")
plt.xlabel("Tid i mikrosekunder")
plt.ylabel("Absolutt feil i mikrometer")
for i in range(dtmax, dtmin):
    t, ax, ay, az, nx, ny, nz, ae, re =np.loadtxt("..//Txtfiler/err{}Euler.txt".format(i), unpack=True)
    plt.plot(t, np.log(ae), label="h=10^-{}".format(i))
plt.legend()
plt.show()
"""
plt.title("Relativ feil med Euler")
plt.xlabel("Tid i mikrosekunder")
plt.ylabel("Relativ feil")
for i in range(dtmax, dtmin):
    t, ax, ay, az, nx, ny, nz, ae, re =np.loadtxt("..//Txtfiler/err{}Euler.txt".format(i), unpack=True)
    plt.plot(t, np.log(re), label="h=10^-{}".format(i))
    maxEu[i]=np.amax(re)
plt.legend()
plt.show()
plt.title("Absolutt feil med Rungekutta 4")
plt.xlabel("Tid i mikrosekunder")
"""
plt.ylabel("Absolutt feil i mikrometer")
for i in range(1, dtmin):
    t, ax, ay, az, nx, ny, nz, ae, re =np.loadtxt("..//Txtfiler/err{}RK4.txt".format(i), unpack=True)
    plt.plot(t, np.log(ae), label="h=10^-{}".format(i))
plt.legend()
plt.show()
"""
plt.title("Relativ feil med Rungekutta 4")
plt.xlabel("Tid i mikrosekunder")
plt.ylabel("Relativ feil")
for i in range(dtmax, dtmin):
    t, ax, ay, az, nx, ny, nz, ae, re =np.loadtxt("..//Txtfiler/err{}RK4.txt".format(i), unpack=True)
    plt.plot(t, np.log(re), label="h=10^-{}".format(i))
    maxRK[i]=np.amax(re)
plt.legend()
plt.show()
print(maxEu)
rerrEu=0
for i in range(dtmax+1, dtmin):
    print(maxEu[i])
    a1=maxEu[i]/maxEu[i-1]
    print(a1)
    a2=(10**(-i))/(10**(-i-1))
    rerrEu+=np.log(a1)/np.log(a2)
rerrEU=rerrEu/4
print("rerrEu", rerrEu)
rerrRK=0
for i in range(dtmax+1, dtmin):
    print(maxRK[i])
    a1=maxRK[i]/maxRK[i-1]
    print(a1)
    a2=(10**(-i))/(10**(-i-1))
    rerrRK+=np.log(a1)/np.log(a2)
rerrRK=rerrRK/4
print("rerrRK4", rerrRK)
"""
t, ax, ay, az, nx, ny, nz, ae, re =np.loadtxt("..//Txtfiler/errdt0.001000RK4.txt", unpack=True)
t2, ax2, ay2, az2, nx2, ny2, nz2, ae2, re2 =np.loadtxt("..//Txtfiler/errdt0.100000RK4.txt", unpack=True)
plt.plot(ax, ay, label="Analytisk")
plt.plot(nx, ny, label="Numerisk")
plt.legend()
plt.show()

plt.title("Absolutt Feil")
plt.plot(t, ae)
plt.plot(t2, ae2)
plt.show()
plt.title("Relativ feil")
plt.plot(t, re)
plt.plot(t2, re2)
plt.show()
"""
