n = int(input())

words = [] # 准备一个新的 list

# range(n) = [0, 1, 2, 3, ..., n]
# 对 range(n) 里的每一个元素 i，也就是 i=0, i=1, i-2
for i in range(n): 
    words.append(input()) # 把 input() 输入的 string 加入到 words 之中

# 对于 words 里的每个元素 word
for word in words:
    # 如果word的长度小于等于10，直接输出 word
    if len(word) <= 10:
        print(word)
    else:
        # 否则输出word的第一个元素、word的长度-2、word的最后一个元素
        # words[-1] 是指从后面算起的第一个元素
        # 下面两种写法都可以
        print(word[0] + str(len(word) - 2) + word[-1])
        # print(f"{word[0]}{len(word)-2}{word[-1]}")
