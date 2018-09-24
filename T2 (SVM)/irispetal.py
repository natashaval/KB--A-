import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm, datasets

iris = datasets.load_iris()
X = iris.data[:,2:4] #ambil petal_length & petal_width
#print (X)

y = iris.target
#print (y)


# jarak antar titik koordinat
h = .02

# Create an instance of SVM and fit out data
# http://scikit-learn.org/stable/modules/generated/sklearn.svm.SVC.html
# C = Penalty parameter C of the error term
# svm.fit(X,y) -> X = training vectors, y = target values (class labels in classification, real in regression)
svc = svm.SVC(kernel='linear', C=1.0).fit(X,y)

# create a mesh to plot in
x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
xx, yy = np.meshgrid(np.arange(x_min, x_max, h),
                     np.arange(y_min, y_max, h))

# perform classification on samples in X
predict = svc.predict(X)
print (predict)

accuracy = svc.score(X,y)
print('accuracy', accuracy)


# title for the plots
titles = ['SVC with linear kernel in PETAL']

print ("------------------")
print (xx)
print ("------------------")
print (xx.ravel())
Z = svc.predict(np.c_[xx.ravel(), yy.ravel()])

# Put the result into a color plot
Z = Z.reshape(xx.shape)
plt.contourf(xx, yy, Z, cmap=plt.cm.copper, alpha=0.8)

# Plot also the training points
plt.scatter(X[:, 0], X[:, 1], c=y, cmap=plt.cm.coolwarm)
plt.xlabel('Petal length')
plt.ylabel('Petal width')
plt.xlim(xx.min(), xx.max())
plt.ylim(yy.min(), yy.max())
#plt.xticks(())
#plt.yticks(())
plt.title(titles[0])

plt.show()

