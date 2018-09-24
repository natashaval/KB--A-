# https://medium.com/machine-learning-101/chapter-2-svm-support-vector-machine-theory-f0812effc72

import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm, datasets

wine = datasets.load_wine()
X = wine.data[:,0:2]
#print(X)

y = wine.target
print(y)

h = .02 #jarak antar titik koordinat

svc = svm.SVC(kernel='linear',C=1.0).fit(X,y)

x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
xx, yy = np.meshgrid(np.arange(x_min, x_max, h),
                     np.arange(y_min, y_max, h))

print(x_min, x_max, y_min, y_max)
#print(xx,yy)
accuracy = svc.score(X,y)
print('accuracy', accuracy)

titles = 'SVC linear kernel in Wine Datasets'
print ("------------------")
print (xx)
print ("------------------")
print (xx.ravel())
Z = svc.predict(np.c_[xx.ravel(), yy.ravel()])


Z = Z.reshape(xx.shape)
plt.contourf(xx, yy, Z, cmap=plt.cm.copper, alpha = 0.5)

plt.scatter(X[:,0], X[:,1], c=y, cmap=plt.cm.coolwarm)
plt.xlabel('Alcohol')
plt.ylabel('Malic Acid')
plt.title(titles)
plt.show()
