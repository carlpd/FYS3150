import matplotlib.pyplot as plt
import numpy as np
from scipy import stats
import sys

Lvalues = np.array(sys.argv[1]) #should be lists
Tvalues = np.array(sys.argv[2])

A = Tvalues*Lvalues
slope, intercept, r-value, p-value, stderr = stats.linregress(Lvalues, A)

print("slope (Tinf):" slope)
print("intercept (a):" intercept)
print("stderr (error):" stderr)
