n = int(input())
s = input().split()

s = sorted(s)

k = 1
prev = s[0]

for i in range(len(s)):
    if s[i] != prev:
        k += 1
        prev = s[i]

print(k)