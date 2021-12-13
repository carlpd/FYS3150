import matplotlib.pyplot as plt
import numpy as np
import pyarma as arma

plt.rcParams.update({
    "text.usetex": True,
    "font.family": "sans-serif",
    "font.sans-serif": ["Helvetica"],
    "font.size": 20})

U=arma.cx_cube()
sl=3
sz=199
U.load(f"../Txt/U1{sz}{sl}.bin")
file=open(f"../Txt/U1{sz}{sl}.bin", "rb")
Ubs=arma.cube()
Ubs=arma.abs(U)
Re = arma.real(U)
Im = arma.imag(U)
s=Ubs.n_slices
#print(Ubs.slice(1))
print(s)
print(arma.size(Ubs))

n = Ubs.n_slices
tt = [0, int(n/8), int(n/4), n-1]
for t in tt:
    Ut = U[:,:,t]
    n = int(U.n_rows)
    Mat = np.zeros((n+1, n+1), dtype=complex)
    for i in range(1, n):
        for k in range(1, n):
            Mat[k][i] = Ut[i, k, 0]
    fig = plt.figure(figsize=(10,8))
    plt.title(f'$ |u|, t = {t*2.5e-1} $')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.imshow(abs(Mat)**2, cmap=plt.get_cmap("viridis"), vmin=0.0, vmax=np.max(abs(Mat)**2), extent=[0, 1, 0, 1])
    plt.colorbar()
    plt.savefig(f'../Images/ImshowUt{t*2.5e-5}sl{sl}.pdf')

    fig = plt.figure(figsize=(10,8))
    plt.title(f'$ Re(u), t = {t*2.5e-1} $')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.imshow(Mat.real, cmap=plt.get_cmap("viridis"), vmin=0.0, vmax=np.max(Mat.real), extent=[0, 1, 0, 1])
    plt.colorbar()
    plt.savefig(f'../Images/ImshowRe{t*2.5e-5}sl{sl}.pdf')


    fig = plt.figure(figsize=(10,8))
    plt.title(f'$ Im(u), t = {t*2.5e-1} $')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.imshow(Mat.imag, cmap=plt.get_cmap("viridis"), vmin=0.0, vmax=np.max(Mat.imag), extent=[0, 1, 0, 1])
    plt.colorbar()
    plt.savefig(f'../Images/ImshowIm{t*2.5e-5}sl{sl}.pdf')


t = 80
i = int(0.8*n)
Vec = np.zeros(n)
for k in range(n):
    Vec[k] = abs(U[i, k, t])**2
sum = np.trapz(Vec, x=np.linspace(0, 1, n))
Vec = Vec/sum
fig = plt.figure(figsize=(10,8))
plt.title(f'$ p(y) \\; , \\;  x = 0.8 \\; , \\; t = 0.002s $')
plt.xlabel('y')
plt.ylabel('$p(y)$')
plt.plot(np.linspace(0, 1, n), Vec)
plt.savefig(f'../Images/ScreenProb{sl}Slit.pdf')
