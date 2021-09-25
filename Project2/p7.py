import numpy as np
import matplotlib.pyplot as plt
mat=np.loadtxt("Data/eigenvecs7.txt")
a=np.zeros(len(mat)+2)
b=np.zeros(len(mat)+2)
c=np.zeros(len(mat)+2)
a[1:-1]=mat[:,0]
b[1:-1]=mat[:,1]
c[1:-1]=mat[:,2]
L=1
x=np.linspace(0,L,len(mat)+2)
mat2=np.loadtxt("Data/eigenvecs7n100.txt")
a2=np.zeros(len(mat2)+2)
b2=np.zeros(len(mat2)+2)
c2=np.zeros(len(mat2)+2)
a2[1:-1]=mat2[:,0]
b2[1:-1]=mat2[:,1]
c2[1:-1]=mat2[:,2]
x2=np.linspace(0,L,len(mat2)+2)
fig=plt.figure(figsize=(10,7))
plt.subplot(2,1,1)
plt.title("n=11", size=20)
plt.ylabel("u(x)", size=20)
plt.xticks(fontsize="x-large")
plt.yticks(fontsize="x-large")
plt.plot(x,a, label="Modul 0")
plt.plot(x,b, label="Modul 1")
plt.plot(x,c, label="Modul 2")
plt.legend()
plt.subplot(2,1,2)
plt.title("n=101", size=20)
plt.plot(x2,a2, label="Modul 0")
plt.plot(x2,b2, label="Modul 1")
plt.plot(x2,c2, label="Modul 2")
plt.xlabel("x", size=20)
plt.ylabel("u(x)", size=20)
plt.xticks(fontsize="x-large")
plt.yticks(fontsize="x-large")
plt.legend()
fig.tight_layout()
plt.savefig("Images/p7.pdf")
plt.show()
