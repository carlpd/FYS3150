import matplotlib.pyplot as plt
import numpy as np
import pyarma as arma

U=arma.cx_cube()
U.load("../Txt/U1.bin")
file=open("../Txt/U1.bin", "rb")
Ubs=arma.cube()
Ubs=arma.abs(U)
s=Ubs.n_slices
print(Ubs.slice(1))
print(s)
print(arma.size(Ubs))

dt = 2.5e-5
tt = [0, 1e-3, 2e-3]
for t in tt:
    k = int(t/dt)
    U = Ubs[:][:][k]
    x = np.arange(0, len(U[0]))
    y = np.arange(0, len(U[1]))
    X, Y = np.meshgrid(x, y)
    fig = plt.figure(figsize=(10,8))
    plt.imshow(U)
    plt.show()
