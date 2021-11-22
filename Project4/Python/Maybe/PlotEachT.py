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
print(t_range)
Holder = np.zeros((len(t_range), len(L_range), 6))
for i, tt in enumerate(t_range):
    for k, LL in enumerate(L_range):
        s, e, e2, m, m2 = np.loadtxt(f'../Txt/ChainT{tt:.6f}L{LL:.0f}.txt', unpack=True)
        sbn.histplot(e/np.sum(e), kde=True, stat="density", label="measured")
        plt.show()
        eps_mean, eps2_mean, m_mean, m2_mean, Cv, X = CalcMeans(e, e2, m, m2)
        Holder[i, k, :] = eps_mean, eps2_mean, m_mean, m2_mean, Cv, X
