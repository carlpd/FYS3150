import numpy as np
import matplotlib.pyplot as plt
import sys
plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 17})

T = float(sys.argv[1])
L= int(sys.argv[2])
K = 1
s, e, e2, m, m2 = np.loadtxt(sys.argv[3], unpack=True)
N=L**2
e = e/N
mean_e = np.zeros_like(e)
for i in range(len(s)):
    mean_e[i] = np.sum(e[:i])/s[i]
fig = plt.figure(figsize=(10,8))
plt.plot(s, mean_e)
plt.xlabel('Monte Carlo Cycles')
plt.ylabel('$\\left <\\epsilon \\right>$')
plt.title(f'$\\left <\\epsilon \\right >$ for $L={L}$, $T = {T}$')
plt.savefig(f'../Images/meanepsT{T}L{L:.0f}.pdf')


m = m/N
mean_m = np.zeros_like(e)
for i in range(len(s)):
    mean_m[i] = np.sum(m[:i])/s[i]
fig = plt.figure(figsize=(10,8))
plt.plot(s, mean_m)
plt.xlabel('Monte Carlo Cycles')
plt.ylabel('$\\left < \\left |m \\right |\\right>$')
plt.title(f'$\\left <\\left |m \\right | \\right >$ for $L={L}$')
plt.savefig(f'../Images/meanmT{T}L{L}.pdf')
