n = int(input())
a = [int(x) for x in input().split()]

mi = min(a)
c = a.count(mi)

if c>=2:
    print("Still Rozdil")
else:
    print(a.index(mi)+1)
