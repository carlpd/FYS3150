import numpy as np
import matplotlib.pyplot as plt
import sys
K = 1
L=int(sys.argv[1])
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

def plotVal(Hold, L, i, xname, yname, Ttl, t_range):
    fig = plt.figure(figsize=(10,8))
    plt.xlabel(xname)
    plt.ylabel(yname)
    plt.title(Ttl)
    plt.plot(t_range, Hold[:, i])
    name = '../Images/' + f'L{L}' + yname + '.pdf'
    plt.savefig(name)

t_range = np.loadtxt('../Txt/T.txt')
L_range = np.loadtxt('../Txt/L.txt')
print(t_range)
Holder = np.zeros((len(t_range), 6))
for i, tt in enumerate(t_range):
        print(i)
        s, e, e2, m, m2 = np.loadtxt(f'../Txt/ChainT{tt:.6f}L{L}.txt', unpack=True)
        eps_mean, eps2_mean, m_mean, m2_mean, Cv, X = CalcMeans(e, e2, m, m2)
        Holder[i, :] = eps_mean, eps2_mean, m_mean, m2_mean, Cv, X

for i, dd in enumerate(['eps_mean', 'eps2_mean', 'm_mean', 'm2_mean', 'Cv', 'X']):
    plotVal(Holder, 10, i, 'T', dd, f'{dd} for L = {L}', t_range)
