import myfibo

if __name__ == '__main__':
	
	i = 0
	while i <= 10:
		print("fibo_naive("+str(i)+") = "+str(myfibo.fibo_naive(i)))
		i=i+1

	i = 0
	while i <= 10:
		print("fibo_iterative("+str(i)+") = "+str(myfibo.fibo_iterative(i)))
		i=i+1

