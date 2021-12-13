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
sl=2
Pebs.load(f"../Txt/P1{sz}{sl}.bin")
file=open(f"../Txt/P1{sz}{sl}.bin", "rb")
P=arma.abs(Pebs)-1
Parray = np.zeros(P.n_rows)
print(P.n_rows)
I = np.arange(0, P.n_rows)
for i in range(P.n_rows):
    Pi = np.zeros(P.n_cols)
    Pi[:] = P[i, :]
    Parray[i] = np.sum(Pi)
print(np.size(I))
plt.plot(I[:-1], Parray[:-1])
plt.xlabel('Tid [s]')
<<<<<<< HEAD
plt.ylabel('|u^2|')
plt.title(f'1 - P , sz = {sz}')
plt.savefig(f'../Images/P{sz}{sl}.pdf')
=======
plt.ylabel('$|u^2|$')
plt.title(f'$1 - P $, $sz = {sz}$')
plt.savefig(f'../Images/P{sz}.pdf')
>>>>>>> 35cb7919b0677f22fcf91948fc714a33278fdb02
