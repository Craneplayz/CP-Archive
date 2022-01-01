n=int(input())

if n == 1:
    print(1)
elif n<=3:
    print("NO SOLUTION")
else:
    a=[]
    b=[]
    for i in range(1,n+1):
        if i%2 :
            b.append(i)
        else :
            a.append(i)
    print(*(a+b),sep=" ")