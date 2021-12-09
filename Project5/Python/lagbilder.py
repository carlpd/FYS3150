import matplotlib.pyplot as plt
import numpy as np
import pyarma as arma

U=arma.cx_cube()
U.load("../Txt/U1.bin")
file=open("../Txt/U1.bin", "rb")
Ubs=arma.cube()
Ubs=arma.abs(U)
s=Ubs.n_slices
#print(Ubs.slice(1))
print(s)
print(arma.size(Ubs))

n = Ubs.n_slices
tt = [0, int(n/2), n-1]
for t in tt:
    U = Ubs[:,:,t]
    n = int(U.n_rows)
    Mat = np.zeros((n, n))
    for i in range(n):
        for k in range(n):
            Mat[i][k] = U[i, k, 0]
    fig = plt.figure(figsize=(10,8))
    plt.title(f'n = {t}')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.imshow(Mat)
    plt.savefig(f'../Images/ImshowUt{t}.pdf')
