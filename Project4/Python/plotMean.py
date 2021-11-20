import numpy as np
import matplotlib.pyplot as plt
import sys
plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 20})

T = float(sys.argv[1])
L= int(sys.argv[2])
K = 1
s, e, e2, m, m2 = np.loadtxt(sys.argv[3], unpack=True)
sg, eg, e2g, mg, m2g = np.loadtxt(sys.argv[4], unpack=True)
N=L**2
e = e/N
eg = eg/N
mean_e = np.zeros_like(e)
for i in range(len(s)):
    mean_e[i] = np.sum(e[:i])/s[i]
mean_eg = np.zeros_like(eg)
for i in range(len(sg)):
    mean_eg[i] = np.sum(eg[:i])/sg[i]
fig = plt.figure(figsize=(10,8))
plt.plot(s/N, mean_e, label='Tilfeldig $s_0$')
plt.plot(s/N, mean_eg, label='Grunntilstand')
plt.xlabel('Monte Carlo Sykluser')
plt.ylabel('$\\left <\\epsilon \\right>$')
plt.title(f'$\\left <\\epsilon \\right >$ for $L={L}$, $T = {T}$')
plt.legend()
plt.savefig(f'../Images/meanepsT{T}L{L:.0f}.pdf')


m = m/N
mg = mg/N
mean_m = np.zeros_like(e)
for i in range(len(s)):
    mean_m[i] = np.sum(m[:i])/s[i]

mean_mg = np.zeros_like(eg)
for i in range(len(sg)):
    mean_mg[i] = np.sum(mg[:i])/sg[i]
fig = plt.figure(figsize=(10,8))
plt.plot(s/N, mean_m, label='Tilfeldig $s_0$')
plt.plot(s/N, mean_mg, label='Grunntilstand')
plt.xlabel('Monte Carlo Sykluser')
plt.ylabel('$\\left < \\left |m \\right |\\right>$')
plt.title(f'$\\left <\\left |m \\right | \\right >$ for $L={L}$. $T = {T}$')
plt.legend()
plt.savefig(f'../Images/meanmT{T}L{L}.pdf')
