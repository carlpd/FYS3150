import matplotlib.pyplot as plt
import numpy as np
import pyarma as arma

plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 20})

fig = plt.figure(figsize=(10, 8))
Pebs=arma.mat()
sz=199
Pebs.load(f"../Txt/7P1{sz}1.bin")
file=open(f"../Txt/7P1{sz}1.bin", "rb")
P=arma.abs(Pebs)-1
Parray = np.zeros(P.n_rows)
print(P.n_rows)
I = np.arange(0, P.n_rows)
for i in range(P.n_rows):
    Pi = np.zeros(P.n_cols)
    Pi[:] = P[i, :]
    Parray[i] = np.sum(Pi)
print(np.size(I))
plt.plot(I[:-1]*2.5e-5, Parray[:-1])
plt.xlabel('Tid [s]')
plt.ylabel('$1 - P$')
plt.title(f'$1 - P $, $sz = {sz}$')
plt.savefig(f'../Images/7P{sz}.pdf')
