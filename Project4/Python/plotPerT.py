import numpy as np
import matplotlib.pyplot as plt
import sys
K = 1
#L=int(sys.argv[1])
#N=L**2

#L_range = np.loadtxt('../Txt/L.txt')
"""
T, e, e2, m, m2 = np.loadtxt(f'../Txt/v2PerTemp{L}.txt', unpack=True)
sort = np.argsort(T)
T, e, e2, m, m2 = T[sort], e[sort], e2[sort], m[sort], m2[sort]

Cv = 1/N*(1/(K*T**2))*(e2-e**2)
X = 1/N*(1/(K*T**2))*(m2-m**2)

e, e2, m, m2 = e/N, e2/N, m/N, m2/N
"""
N = 100*100
T_1, e_1, e2_1, m_1, m2_1 = np.loadtxt(f'../Txt/v4PerTemp100.txt', unpack=True)
sort = np.argsort(T_1)
T_1, e_1, e2_1, m_1, m2_1 = T_1[sort], e_1[sort]/N, e2_1[sort]/N, m_1[sort]/N, m2_1[sort]/N
Cv_1 = 1/(100*100)*(1/(T_1**2))*(e2_1-e_1**2)
X_1 = 1/(100*100)*(1/(T_1**2))*(m2_1-m_1**2)
e_1, e2_1, m_1, m2_1 = e_1/N, e2_1/N, m_1/N, m2_1/N

T_2, e_2, e2_2, m_2, m2_2 = np.loadtxt(f'../Txt/v2PerTemp60.txt', unpack=True)
sort = np.argsort(T_2)
T_2, e_2, e2_2, m_2, m2_2 = T_2[sort], e_2[sort], e2_2[sort], m_2[sort], m2_2[sort]
Cv_2 = 1/(60*60)*(1/(T_2**2))*(e2_2-e_2**2)
X_2 = 1/(60*60)*(1/(T_2**2))*(m2_2-m_2**2)
N = 60*60
e_2, e2_2, m_2, m2_2 = e_2/N, e2_2/N, m_2/N, m2_2/N

T_3, e_3, e2_3, m_3, m2_3 = np.loadtxt(f'../Txt/PerTemp40.txt', unpack=True)
sort = np.argsort(T_3)
T_3, e_3, e2_3, m_3, m2_3 = T_3[sort], e_3[sort], e2_3[sort], m_3[sort], m2_3[sort]
Cv_3 = 1/(40*40)*(1/(T_3**2))*(e2_3-e_3**2)
X_3 = 1/(40*40)*(1/(T_3**2))*(m2_3-m_3**2)
N = 40*40
e_3, e2_3, m_3, m2_3 = e_3/N, e2_3/N, m_3/N, m2_3/N


Llist = [100, 60, 40]
plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 20})

fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ \left < \\epsilon \\right >$')
for i in [1, 2, 3]:
    exec(f'plt.plot(T_{i}, e_{i}, label="L = {Llist[i-1]}")')
plt.legend()
plt.savefig(f'../Images/epsperTAll.pdf')


fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ \left < \\epsilon^2 \\right >$')

for i in [1, 2, 3]:
    exec(f'plt.plot(T_{i}, e2_{i}, label="L = {Llist[i-1]}")')
plt.legend()
plt.savefig(f'../Images/eps2perTAll.pdf')


fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ \left < m \\right >$')

for i in [1, 2, 3]:
    exec(f'plt.plot(T_{i}, m_{i}, label="L = {Llist[i-1]}")')
plt.legend()
plt.savefig(f'../Images/mperTAll.pdf')


fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ \left < m^2 \\right > $')

for i in [1, 2, 3]:
    exec(f'plt.plot(T_{i}, m2_{i}, label="L = {Llist[i-1]}")')
plt.legend()
plt.savefig(f'../Images/m2perTAll.pdf')

fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.ylabel('$ X$')

for i in [1, 2, 3]:
    exec(f'plt.plot(T_{i}, X_{i}, label="L = {Llist[i-1]}")')
plt.legend()
plt.savefig(f'../Images/XperTAll.pdf')


fig = plt.figure(figsize=(10,8))
plt.xlabel('$T  \\; [J/k_B]$')
plt.    ylabel('$ C_v$')

for i in [1, 2, 3]:
    exec(f'plt.plot(T_{i}, Cv_{i}, label="L = {Llist[i-1]}")')
plt.legend()
plt.savefig(f'../Images/CvperTAll.pdf')
