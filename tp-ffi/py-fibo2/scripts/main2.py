import matplotlib
import myfibo
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import numpy as np


def test_func(x: int):
    return x*x


if __name__ == '__main__':

    xs = [0]
    i = 1
    while i <= 10:
        xs.append(myfibo.fibo_naive(i))
        i = i + 1
    ys = np.vectorize(test_func)(xs)

    fig, ax = plt.subplots()
    ax.plot(xs, ys)
    ax.set(xlabel='i', ylabel='test_func(i)')
    ax.grid()

    fig.savefig("output.png")
    plt.show()

