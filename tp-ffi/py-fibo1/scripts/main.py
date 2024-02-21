from mypackage.myfibo import *


if __name__ == '__main__':

	print('TODO')
	
	# TODO print fibo_naive(i) for i from 0 to 10
	i = 0
	while i <= 10:
		print("fibo_naive("+str(i)+") = "+str(fibo_naive(i)))
		i=i+1

	# TODO print fibo_iterative(i) for i from 0 to 10
	i = 0
	while i <= 10:
		print("fibo_iterative("+str(i)+") = "+str(fibo_iterative(i)))
		i=i+1

