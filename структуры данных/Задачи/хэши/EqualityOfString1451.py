def check(a, b, n, i, k):
    # до i-1 го символа все проверено
    if hash(a) == hash(b):
        return True
    if i >= n:
        return False
    f = True
    c = a[i]
    for i in range(i + k - 1):
        if a[i] != c:
            f = False
            break
    list_a = list(a)
    if f:
        c_plus = chr(ord(c) + 1)
        for i in range(n - k):
            list_a[i] = c_plus
        a = str(list_a)
    list_a[i], list_a[i + 1] = list_a[i + 1], list_a[i]
    a_1 = a[::]
    a = str(list_a)
    return check(a_1, b, n, i + 1, k) and check(a, b, n, i + 1, k)

    
    





t = int(input())

for i in range(t):
    n, k = input().split()
    n = int(n) # длина a и b
    k = int(k)
    a = input()
    b = input()
    if check(a, b, n, 0, k):
        print("Yes")
    else:
        print("No")

