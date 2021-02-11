sol = {
    '+' : [('chet', 'nechet')],
    'X' : [('nechet', 'nechet')]
}
n = int(input())
numbers = list(map(int, input().split()))
flag = False # пока четно
signs = []
a = numbers[0]
flagChet = a % 2 == 0
for i in range(n - 1):
    b = numbers[i + 1]
    c = numbers[i]
    if flagChet and abs(b) % 2 != 0:
        flagChet = False
        a = a + b
        signs.append('+')
    elif not flagChet and abs(b) % 2 == 0:
        a = a + b
        signs.append('+')
    elif not flagChet and abs(b) % 2 != 0:
        a += c * b
        signs.append('*')
print(signs)
