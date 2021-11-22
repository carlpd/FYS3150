import numpy as np
import matplotlib.pyplot as plt
import seaborn as sbn

K = 1
L=20
N=L**2
T = 2.4

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

t_range = np.loadtxt('../Txt/T.txt')
L_range = np.loadtxt('../Txt/L.txt')
plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 20})
print(t_range)
Holder = np.zeros((len(t_range), len(L_range), 6))

plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 20})

for tt in [1, 2.4]:
        LL = 20
        s, e, e2, m, m2 = np.loadtxt(f'../Txt/ChainT{tt:.6f}L{LL:.0f}.txt', unpack=True)
        eps = e/N
        eps2 = e2/N
        Mn = m/N
        M2n = m2/N
        fig = plt.figure(figsize=(10,8))
        plt.title(f'T = {tt:.1f} og L = {LL:.0f}')
        plt.xlabel('$\epsilon$')
        sbn.histplot(eps, kde=True, stat="density", label="measured")
        plt.savefig(f'../Images/T{tt:.2f}L{LL:.0f}.pdf')
        plt.show()
