def solve():
    libra = []
    c = ()
    for _ in range(3):
        ai, bi, ci = input().split()
        libra.append((ai, bi))

        if ci == "down":
            ci = -1
        elif ci == "even":
            ci = 0
        else:
            ci = 1

        c = (*c, ci)

    alpha2index = lambda xs: [ord(x) - ord("A") for x in xs]

    results = []
    for i in range(12):
        result = ()
        for a, b in libra:
            ai = alpha2index(a)
            bi = alpha2index(b)

            w1 = 0 if i in ai else 1
            w2 = 0 if i in bi else 1

            if w1 == w2:
                result = (*result, 0)  # even
            elif w1 < w2:
                result = (*result, 1)  # up
            else:
                result = (*result, -1)  # down

        results.append(result)

    if c in results:
        try:
            ans = results.index(c)
        except:
            pass
        else:
            ans = chr(ans + ord("A"))
            print(f"{ans} is the counterfeit and it is light.")
    else:
        c = tuple(-x for x in c)
        try:
            ans = results.index(c)
        except:
            pass
        else:
            ans = chr(ans + ord("A"))
            print(f"{ans} is the counterfeit and it is heavy.")


n = int(input())
for _ in range(n):
    solve()
