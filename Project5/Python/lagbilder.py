import matplotlib.pyplot as plt
import numpy as np
import pyarma as arma

U=arma.cx_cube()
U.load("../Txt/U1.bin")
#file=open("../Txt/U1.bin", "rb")
Ubs=arma.cube()
Ubs=arma.abs(U)
s=Ubs.n_slices
print(s)
print(arma.size(Ubs))
#print(Ubs)
