# https://stackoverflow.com/questions/49767638/want-genuine-suggestion-to-build-support-vector-machine-in-python-without-using
import numpy as np
def my_svm(dataset, label):
    rate = 1 #rate for gradient descent
    epochs = 10000 # no of iterations
    weights = np.zeros(dataset.shape[1])

    # Min. the objective function (Hinge loss) by gradient descent
    for epoch in range(1,epochs):
        for n, data in enumerate(dataset):
            if (label[n] * np.dot(dataset[n], weights)) < 1:
                weights = weights + rate * ( (dataset[n] * label[n]) + (-2  *(1/epoch)* weights) )    
            else:
                weights = weights + rate * (-2  * (1/epoch) * weights)

    return weights

def predict(test_data, weights):
    results = []
    for data in test_data:
        result = np.dot(data, weights)
        results.append(-1 if result < 0 else 1)
    return results

dataset = np.array([
        [-2, 4,-1], #x_cood,y_cood,bias
        [4, 1, -1],
        [0, 2, -1],
        [1, 6, -1],
        [2, 5, -1],
        [6, 2, -1]
        ])
label = np.array([-1,-1,-1,1,1,1])

weights = my_svm(dataset,label)
print(weights)

test_data = np.array([
                [0,3,-1], #Should belong to -1
                [4,5,-1]  #Should belong to 1
                ])
print(predict(test_data, weights))
