import matplotlib.pyplot as plt
import numpy as np
from scipy import stats
import sys

#L_range = np.loadtxt('../Txt/L.txt')
T_1, e_1, e2_1, m_1, m2_1 = np.loadtxt(f'../Txt/v4PerTemp100.txt', unpack=True)
sort = np.argsort(T_1)
T_1, e_1, e2_1, m_1, m2_1 = T_1[sort], e_1[sort]/10000, e2_1[sort]/10000, m_1[sort]/10000, m2_1[sort]/10000

Cv_1 = 1/(100*100)*(1/(T_1**2))*(e2_1-e_1**2)


T_2, e_2, e2_2, m_2, m2_2 = np.loadtxt(f'../Txt/v2PerTemp60.txt', unpack=True)
sort = np.argsort(T_2)
T_2, e_2, e2_2, m_2, m2_2 = T_2[sort], e_2[sort], e2_2[sort], m_2[sort], m2_2[sort]

Cv_2 = 1/(60*60)*(1/(T_2**2))*(e2_2-e_2**2)

T_3, e_3, e2_3, m_3, m2_3 = np.loadtxt(f'../Txt/PerTemp40.txt', unpack=True)
sort = np.argsort(T_3)
T_3, e_3, e2_3, m_3, m2_3 = T_3[sort], e_3[sort], e2_3[sort], m_3[sort], m2_3[sort]

Cv_3 = 1/(40*40)*(1/(T_3**2))*(e2_3-e_3**2)

Lvalues = np.array([40, 60, 100])
Tc1 = T_1[np.where(np.amax(Cv_1))[0]]
print(Tc1)
Tc2 = T_2[np.where(np.amax(Cv_2))[0]]
Tc3 = T_3[np.where(np.amax(Cv_3))[0]]
Tvalues = np.array([Tc3[0], Tc2[0], Tc1[0]])

A = Tvalues*Lvalues
slope, intercept, rvalue, pvalue, stderr = stats.linregress(Lvalues, A)

print("slope (Tinf):", slope)
print("intercept (a):", intercept)
print("stderr (error):", stderr)
