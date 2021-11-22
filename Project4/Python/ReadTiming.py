import numpy as np

T = np.loadtxt('../Txt/Time.txt')
Tp = np.loadtxt('../Txt/TimePar.txt')

print(np.mean(T), np.mean(Tp), np.mean(T)/np.mean(Tp))
