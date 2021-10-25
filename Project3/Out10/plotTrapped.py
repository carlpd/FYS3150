import numpy as np
import matplotlib.pyplot as plt

f, oV, Trapped = np.loadtxt('Trapped.txt', unpack=True)
fi = [0.1, 0.4, 0.7]
fig, ax = plt.subplots(3)
for i, ff in enumerate(fi):
    ax[i].set_title(f'f = {ff}')
    ax[i].set_xlabel('Frekvens [MHz]')
    ax[i].set_ylabel('Antall partikkler i fellen etter 500 mikrosekunder')
    ax[i].plot(oV[np.where(f==ff)], Trapped[np.where(f==ff)])
plt.show()
