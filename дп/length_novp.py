def novp(A):
    F = [0]*len(A)
    for i in range(len(A)):
        for j in range(i):
            if A[j] < A[i] and F[j] > F[i]:
                F[i] = F[j]
        F[i]+=1

def novp2(A):
    INF = 10 ** 10
    F = [INF] * (len(A) + 1)
    F[0] = -INF
    for i in range(len(A)):
        left = 0
        right = len(A)
        while right - left > 1:
            middle = (left + right) // 2
            if F[middle] >= A[i]:
                right = middle
            else:
                left = middle
        F[right] = A[i]
