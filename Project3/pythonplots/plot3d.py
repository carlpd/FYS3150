import matplotlib.pyplot as plt
import numpy as np

t, x1, y1, z1, x2, y2, z2=np.loadtxt("../Txtfiler/r2noint.txt", unpack=True)

from mpl_toolkits import mplot3d

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot(x1, y1, z1, label="Partikkel 1")
ax.plot(x2, y2, z2, label="Partikkel 2")
ax.set_xlabel("x posisjon i mikrometer")
ax.set_ylabel("y posisjon i mikrometer")
ax.set_zlabel("z posisjon i mikrometer")
ax.legend()
plt.savefig("3dr2noint.pdf")
plt.show()

t, x1, y1, z1, x2, y2, z2=np.loadtxt("../Txtfiler/r2int.txt", unpack=True)

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot(x1, y1, z1, label="Partikkel 1")
ax.plot(x2, y2, z2, label="Partikkel 2")
ax.set_xlabel("x posisjon i mikrometer")
ax.set_ylabel("y posisjon i mikrometer")
ax.set_zlabel("z posisjon i mikrometer")
ax.legend()
plt.savefig("3dr2int.pdf")
plt.show()
