
# def f(n):
#     if n==0:
#         return 1
#     return f(n-1) + f(n-2)

a = int(input())
b = int(input())

# f(x, y) = z

def f(x, y):
    return x+y

print(a+b, f(a,b))