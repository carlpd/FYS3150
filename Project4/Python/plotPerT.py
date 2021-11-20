import numpy as np
import matplotlib.pyplot as plt
import sys
K = 1
L=int(sys.argv[1])
N=L**2

L_range = np.loadtxt('../Txt/L.txt')
T, e, e2, m, m2 = np.loadtxt(f'../Txt/PerTemp{L}.txt', unpack=True)
sort = np.argsort(T)
T, e, e2, m, m2 = T[sort], e[sort], e2[sort], m[sort], m2[sort]

Cv = 1/N*(1/(K*T**2))*(e2-e**2)
X = 1/N*(1/(K*T**2))*(m2-m**2)

e, e2, m, m2 = e/N, e2/N, m/N, m2/N

plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 20})

fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ <\\epsilon>$')
plt.plot(T, e)
plt.savefig('../Images/epsperT.pdf')


fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ <\\epsilon^2>$')
plt.plot(T, e2)
plt.savefig('../Images/eps2perT.pdf')


fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ <|m|>$')
plt.plot(T, m)
plt.savefig('../Images/mperT.pdf')


fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ <m^2>$')
plt.plot(T, m2)
plt.savefig('../Images/m2perT.pdf')

fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ X$')
plt.plot(T, X)
plt.savefig('../Images/XperT.pdf')


fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.    ylabel('$ C_v$')
plt.plot(T, Cv)
plt.savefig('../Images/CvperT.pdf')
