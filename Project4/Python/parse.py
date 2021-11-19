import numpy as np

order = [1, 2, 3, 4, 5, 6, 7, 8]
ran = np.array([2, 4, 5, 1, 8, 6, 7, 3])
sort = np.argsort(ran)
T = ran[sort]
print(T)
