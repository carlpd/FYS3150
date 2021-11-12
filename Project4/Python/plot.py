import numpy as np
import matplotlib.pyplot as plt


K = 1
s, e, e2, m, m2 = np.loadtxt('../Txt/Chain.txt', unpack=True)
L=2
T = 1
B = 1/(K*T**2)
Z = 12 + 4*np.cosh(8*B)
E2mean = (248*np.sinh(8*B))/(12+4*np.cosh(8*B))
Emean = -(32*np.sinh(8*B))/(12+4*np.cosh(8*B))
Mmean = (8*np.exp(8*B)+16)/(12+4*np.cosh(8*B))
Cv = 1/(K*T**2)*(E2mean - Emean**2)
print('E2mean', 'Emean', 'Mmean', 'Cv')
print(E2mean/L**4, Emean/L**2, Mmean/L**2, Cv)

Esum = np.sum(e)
Msum = np.sum(abs(m))
print('epsilon mean = ', Esum/(s[-1]*L**2))
print('magnetism mean = ', Msum/(s[-1]*L**2))

doPlot = 0
if doPlot==1:
    plt.rcParams.update({
        "text.usetex": True,
        "font.family": "sans-serif",
        "font.sans-serif": ["Helvetica"],
        "font.size": 17})

    plt.figure(figsize=(10,8))
    plt.title('Random Initial Spinmatrix')
    plt.xlabel('Monte Carlo Cycles')
    plt.ylabel('$\left < E \\right > / L^2$')
    plt.plot(s, e/L**2)
    plt.savefig('../Images/RISeps.pdf')


    plt.figure(figsize=(10,8))
    plt.title('Random Initial Spinmatrix')
    plt.xlabel('Monte Carlo Cycles')
    plt.ylabel('$\left < E \\right >^2 / L^4$')
    plt.plot(s, e2/L**4)
    plt.savefig('../Images/RISeps2.pdf')

    plt.figure(figsize=(10,8))
    plt.title('Random Initial Spinmatrix')
    plt.xlabel('Monte Carlo Cycles')
    plt.ylabel('$\left < M \\right > / L^2$')
    plt.plot(s, m/L**2)
    plt.savefig('../Images/RISm.pdf')

    plt.figure(figsize=(10,8))
    plt.title('Random Initial Spinmatrix')
    plt.xlabel('Monte Carlo Cycles')
    plt.ylabel('$\left < M \\right >^2 / L^4$')
    plt.plot(s, m2/L**4)
    plt.savefig('../Images/RISm2.pdf')
