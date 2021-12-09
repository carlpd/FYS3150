import matplotlib.pyplot as plt
import numpy as np
import pyarma as arma

Pebs=arma.mat()
sz=199
Pebs.load(f"../Txt/P1{sz}.bin")
file=open(f"../Txt/P1{sz}.bin", "rb")
P=arma.abs(Pebs)
Parray = np.zeros(P.n_rows)
print(P.n_rows)
I = np.arange(0, P.n_rows)
for i in range(P.n_rows):
    Pi = np.zeros(P.n_cols)
    Pi[:] = P[i, :]
    Parray[i] = np.sum(Pi)
print(np.size(I))
plt.plot(I, Parray)
plt.xlabel('Tid [s]')
plt.ylabel('|u^2|')
plt.title(f'1 - P , sz = {sz}')
plt.savefig(f'../Images/P{sz}.pdf')
