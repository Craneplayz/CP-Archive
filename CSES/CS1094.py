n = int(input())
a = [int(x) for x in input().split()]
c = 0

for i in range (1,n) :
    d = a[i-1] - a[i]
    if d>0 :
        c+=d
        a[i]=a[i-1]

print(c)
