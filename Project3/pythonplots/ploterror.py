import matplotlib.pyplot as plt
import numpy as np

t, ax, ay, az, nx, ny, nz, ae, re =np.loadtxt("..//Txtfiler/errdt0.001000RK4.txt", unpack=True)
plt.title("Absolutt Feil")
plt.plot(t, ae)
plt.show()
plt.title("Relativ feil")
plt.plot(t, re)
plt.show()
