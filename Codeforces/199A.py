n = int(input())

F=[0,1]
f=0

while f <= 1e9:
    l = len(F)
    f=F[l-1]+F[l-2]
    F.append(f)

if F.count(n)==0:
    print("I'm too stupid to solve this problem")
else:
    
    if n == 1:
        print(1,0,0,sep=" ")
    elif n==0:
        print(0,0,0,sep=" ")
    elif n==2:
        print(1,1,0,sep=" ")
    else:
        i = F.index(n)
        print(F[i-1],F[i-3],F[i-4],sep=" ")