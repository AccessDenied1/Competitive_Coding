from functools import reduce
# cook your dish here
def fun(index,A,x):
	days = 0

	for i in range(index,len(A)):
		pre = A[i]
		while(A[i] > x):
			days = days+1
			theta = int((A[i]+1)/2)
			if(x < theta):
				theta = x
			else:  			    		
				beta = (A[i]-theta)*2
				A[i] = max(pre,beta)
			x = theta*2
		x = A[i]*2
		days = days+1
	for i in range(index-1,-1,-1):
		pre = A[i]
		while(A[i] > x):
			days = days+1
			theta = int((A[i]+1)/2)
			if(x < theta):
				theta = x
			else:  			    		
				beta = (A[i]-theta)*2
				A[i] = max(pre,beta)
			x = theta*2
		x = A[i]*2
		days = days+1
	return days

def fun2(index,A,x):
	days = 0
	x2 = x
	for i in range(index,len(A)):
		pre = A[i]
		while(A[i] > x):
			days = days+1
			x = x*2
		x = A[i]*2
		days = days+1
	for i in range(index-1,-1,-1):
		pre = A[i]
		while(A[i] > x):
			days = days+1
			x = x*2
		x = A[i]*2
		days = days+1
	day2 = 0
	l1=[]
	l2=[]
	for al in A:
		if(al>=x2):
			l1.append(al)
		else:
			l2.append(al)
	l1.sort()
	l2.sort(reverse = True)
	#print(l1)
	#print(l2)
	for al in l1:
		while(al >x2):
			day2=day2+1
			x2 = x2*2
		x2 = al*2
		day2=day2+1
	for al in l2:
		while(al >x2):
			x2 = x2*2
			day2=day2+1
		x2 = al*2
		day2=day2+1
	return day2

T = int(input())
for al in range(T):

	N, x  = [int(x) for x in input().split()]
	A = [int(x) for x in input().split()]
	A.sort()
	index = 0
	for al in range(len(A)):
		if(A[al]>=x):
			index = al
			break
	ans = fun2(index, A, x)
	if (index!=0 and A[index-1]*2 >= x):
		index = index -1;
	ans = min(ans , fun(index, A, x))
	print(ans)
