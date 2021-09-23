import numpy as np
import matplotlib.pyplot as plt
mat=np.loadtxt("Data/eigenvecs7.txt")
print(mat)
a=np.zeros(len(mat)+2)
b=np.zeros(len(mat)+2)
c=np.zeros(len(mat)+2)
a[1:-1]=mat[:,0]
b[1:-1]=mat[:,1]
c[1:-1]=mat[:,2]
"""
for i in range(len(mat)):
    a[i+1]=mat[i,0]
    b[i+1]=mat[i,1]
    c[i+1]=mat[i,2]
"""
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
fig=plt.figure(figsize=(10,5))
plt.subplot(1,2,1)
plt.title("n=11")
plt.plot(x,a)
plt.plot(x,b)
plt.plot(x,c)
plt.subplot(1,2,2)
plt.title("n=101")
plt.plot(x2,a2)
plt.plot(x2,b2)
plt.plot(x2,c2)
plt.show()
