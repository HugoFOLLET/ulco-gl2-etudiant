
def fibo_naive(n: int):
	assert n >= 0
	return n if n < 2 else fibo_naive(n-1) + fibo_naive(n-2)

# TODO implement fibo_iterative
def fibo_iterative(n: int):
	if n<=0:
		return 0
	i = 1
	k = 0
	l = 1
	while i < n:
		temp = l
		l = l + k
		k = temp
		i=i+1
	return l

