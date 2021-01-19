def search_substring(A, B):
    length = 1
    s = ""
    for i in range(len(A)):
        flag = True
        while flag:
            if A[i:i + length] in B and i + length < len(A):
                length += 1
                if len(s) < length:
                    s = A[i: i + length]
            else:
                flag = False
                length = 1
    return s

def lcsDYN(A,B):
    n = len(A)
    m = len(B)
    F = [[0] * (m + 1) for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if A[i - 1] == B[j - 1]:
                F[i][j] = F[i - 1][j - 1] + 1
            else:
                F[i][j] = max(F[i - 1][j], F[i][j - 1])
    return F[n][m]
def lcsDYNAnswer(A, B, F):
    Ans = []
    i = len(A)
    j = len(B)
    while i > 0 and j > 0:
        if A[i - 1] == B[j - 1]:
            Ans.append(A[i - 1])
            i -= 1
            j -= 1
        elif F[i - 1][j] == F[i][j]:
            i -= 1
        else:
            j -= 1
    Ans = Ans[::-1]
A = input()
B = input()
print(search_substring(A, B))