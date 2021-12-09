import matplotlib.pyplot as plt
import numpy as np
import pyarma as arma

U=arma.cx_cube()
sz=199
U.load(f"../Txt/U1{sz}.bin")
file=open(f"../Txt/U1{sz}.bin", "rb")
Ubs=arma.cube()
Ubs=arma.abs(U)
s=Ubs.n_slices
#print(Ubs.slice(1))
print(s)
print(arma.size(Ubs))

n = Ubs.n_slices
tt = [0, 2, 5, 7, 10, 15, 20, 25, 30, 35, 40, 60, int(n/4), int(n/2), n-1]
for t in tt:
    U = Ubs[:,:,t]
    n = int(U.n_rows)
    Mat = np.zeros((n, n))
    for i in range(n):
        for k in range(n):
            Mat[k][i] = U[i, k, 0]
    fig = plt.figure(figsize=(10,8))
    plt.title(f'n = {t*2.5e-5}')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.imshow(Mat, cmap=plt.get_cmap("viridis"), vmin=0.0, vmax=np.max(Mat))
    plt.colorbar()
    plt.savefig(f'../Images/ImshowUt{t*2.5e-5}.pdf')
