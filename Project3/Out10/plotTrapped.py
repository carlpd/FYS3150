import numpy as np
import matplotlib.pyplot as plt

font = {'size'   : 17}

plt.rc('font', **font)


f, oV, Trapped = np.loadtxt('Trapped.txt', unpack=True)
fi = [0.1, 0.4, 0.7]
Trapped = Trapped/100
for i, ff in enumerate(fi):
    fig = plt.figure(figsize=(9,6))
    ax=plt.axes()
    title = f'f={ff}'
    ax.set_title(title)
    ax.set_xlabel('Frekvens [MHz]')
    ax.set_ylabel('Andel partikkler i fellen etter 500 µs')
    ax.plot(oV[np.where(f==ff)], Trapped[np.where(f==ff)])
    plt.savefig(f'../Images/{i}Trapped.pdf')


font = {'size'   : 20}

plt.rc('font', **font)


fig2 = plt.figure(figsize=(9,8))
ax2 = plt.axes(title='Amplitude 0.4, med Coloumb interaksjoner.')
ax2.set_xlabel('Frekvens [MHz]')
ax2.set_ylabel('Andel fanget etter 500 µs')
f, oV, Trapped = np.loadtxt('TrappedColoumb.txt', unpack=True)
Trapped = Trapped/100
ax2.plot(oV, Trapped)
plt.savefig('../Images/TrappedColoumb.pdf')

fig2 = plt.figure(figsize=(10,8))
ax2 = plt.axes(title='Amplitude 0.4, uten Coloumb interaksjoner.')
ax2.set_xlabel('Frekvens [MHz]')
ax2.set_ylabel('Andel fanget etter 500 µs')
f, oV, Trapped = np.loadtxt('TrappedZoomed.txt', unpack=True)
Trapped = Trapped/100
ax2.plot(oV, Trapped)
plt.savefig('../Images/TrappedZoomed.pdf')
