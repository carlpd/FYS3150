import matplotlib.pyplot as plt
import numpy as np
import pyarma as arma

plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 20})

U=arma.cx_cube()
sz=199
U.load(f"../Txt/U1{sz}.bin")
file=open(f"../Txt/U1{sz}.bin", "rb")
Ubs=arma.cube()
Ubs=arma.abs(U)
Re = arma.real(U)
Im = arma.imag(U)
s=Ubs.n_slices
#print(Ubs.slice(1))
print(s)
print(arma.size(Ubs))

n = Ubs.n_slices
tt = [0, 2, 5, 7, 10, 15, 20, 25, 30, 35, 40, 60, int(n/4), int(n/2), n-1]
for t in tt:
    Ut = U[:,:,t]
    n = int(U.n_rows)
    Mat = np.zeros((n, n), dtype=complex)
    for i in range(n):
        for k in range(n):
            Mat[k][i] = Ut[i, k, 0]
    fig = plt.figure(figsize=(10,8))
    plt.title(f'$ |u| \\; , \\; , t = {t*2.5e-5} $')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.imshow(abs(Mat), cmap=plt.get_cmap("viridis"), vmin=0.0, vmax=np.max(abs(Mat)))
    plt.colorbar()
    plt.savefig(f'../Images/ImshowUt{t*2.5e-5}.pdf')

    fig = plt.figure(figsize=(10,8))
    plt.title(f'$ Re(u) \\; , \\; , t = {t*2.5e-5} $')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.imshow(Mat.real, cmap=plt.get_cmap("viridis"), vmin=0.0, vmax=np.max(Mat.real))
    plt.colorbar()
    plt.savefig(f'../Images/ImshowRe{t*2.5e-5}.pdf')

    fig = plt.figure(figsize=(10,8))
    plt.title(f'$ Im(u) \\; , \\; , t = {t*2.5e-5} $')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.imshow(Mat.imag, cmap=plt.get_cmap("viridis"), vmin=0.0, vmax=np.max(Mat.imag))
    plt.colorbar()
    plt.savefig(f'../Images/ImshowIm{t*2.5e-5}.pdf')
