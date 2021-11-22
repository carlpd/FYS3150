import numpy as np
import matplotlib.pyplot as plt
import seaborn as sbn
K = 1
s, e, e2, m, m2 = np.loadtxt('../Txt/ChainT1.000000L2.txt', unpack=True)
L=2
N=L**2
T = 1
B = 1/(K*T**2)
Z = 12 + 4*np.cosh(8*B)
E2mean = (16**2*np.sinh(8*B))/(12+4*np.cosh(8*B))
Emean = -(32*np.sinh(8*B))/(12+4*np.cosh(8*B))
Mmean = (8*np.exp(8*B)+4)/(12+4*np.cosh(8*B))
M2mean = (32*np.exp(8*B)+8)/(12+4*np.cosh(8*B))
Cv = 1/N*(K*T**2)*(E2mean - Emean**2)
X = 1/N*(1/(K*T**2))*(M2mean-Mmean**2)
print('E2mean', 'Emean', 'Mmean', 'M2mean','Cv', 'X')
print(E2mean/L**4, Emean/L**2, Mmean/L**2, M2mean/L**4, Cv, X)

Enmean=np.mean(e)
Mnmean=np.mean(np.abs(m))
epsexpv=Enmean/(L**2)
mlexpv=Mnmean/(L**2)
E2mean=np.mean(e2)
M2mean=np.mean(m2)
eps2expv=E2mean/(L**4)
ml2expv=M2mean/(L**4)
Xexp = X = 1/N*(1/(K*T**2))*(M2mean-Mnmean**2)
Cv = 1/N*(1/(K*T**2))*(E2mean-Enmean**2)
print('epsilon mean = ', epsexpv)
print('magnetism mean = ', mlexpv)
print('epsilon2 mean = ', eps2expv)
print('magnetism2 mean = ', ml2expv)
print('X =', Xexp)
print('Cv =', Cv)
#Funksjon for å finne <E>, <E^2>, <M>, <M^2>, Cv og X
def CalcMeans(e, e2, m, m2):
    Enmean=np.mean(e)
    Mnmean=np.mean(np.abs(m))
    E2mean = np.mean(e2)
    M2mean = np.mean(m2)
    Cv = 1/N*(1/(K*T**2))*(E2mean-Enmean**2)
    X = 1/N*(1/(K*T**2))*(M2mean-Mnmean**2)
    eps_mean = Enmean/N
    eps2_mean = E2mean/N
    m_mean = Mnmean/N
    m2_mean = M2mean/N
    return eps_mean, eps2_mean, m_mean, m2_mean, Cv, X

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

    plt.figure(figsize=(10,8))
    plt.title("Histogram")
    plt.xlabel("Epsilon")
    plt.ylabel("P(eps)")
    sbn.histplot(e/N, kde=True, stat="density", label="measured")
    plt.savefig("../Images/Histplot.pdf")
