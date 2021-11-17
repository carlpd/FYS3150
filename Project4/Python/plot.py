import numpy as np
import matplotlib.pyplot as plt
import seaborn as sbn
K = 1
s, e, e2, m, m2 = np.loadtxt('../Txt/ChainT2.400000L20.txt', unpack=True)
L=20
N=L**2
T = 2.4
B = 1/(K*T**2)
Z = 12 + 4*np.cosh(8*B)
E2mean = (248*np.sinh(8*B))/(12+4*np.cosh(8*B))
Emean = -(32*np.sinh(8*B))/(12+4*np.cosh(8*B))
Mmean = (8*np.exp(8*B)+16)/(12+4*np.cosh(8*B))
Cv = 1/(K*T**2)*(E2mean - Emean**2)
print('E2mean', 'Emean', 'Mmean', 'Cv')
print(E2mean/L**4, Emean/L**2, Mmean/L**2, Cv)

epssum = np.sum(e/L**2)
Esum = np.sum(e)
Msum = np.sum(abs(m))
Enmean=np.mean(e)
print("Snitt E =", Enmean/L**2)
Mnmean=np.mean(np.abs(m))
print("Snitt M=", Mnmean/L**2)
Eexpv=Esum/(len(e))
epsexpv=Esum/(len(e)*L**2)
mlexpv=Msum/(len(m)*L**2)
print('epsilon mean = ', epsexpv)
print('magnetism mean = ', mlexpv)
E2sum=np.sum(e2)
M2sum=np.sum(m2)
eps2expv=E2sum/(len(e2)*L**2)
ml2expv=M2sum/(len(m2)*L**2)
print('epsilon2 mean = ', eps2expv)
print('magnetism2 mean = ', ml2expv)

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

doPlot = 1
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
