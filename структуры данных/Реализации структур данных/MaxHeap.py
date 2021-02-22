# put your python code here
class Heap:
    def __init__(self):
        self.arr = []
    def insert(self, x):
        #finalLevel = 0
        #try:
        #   finalLevel = int(log(len(self.arr), 2))
        #except:
        #   pass
        #max_count = 2 ** (finalLevel - 1)
        #start_index = max_count + 1
        #choiced = choice([x for x in range(start_index, start_index + max_count)])
        self.arr.append(x)
        i = len(self.arr) - 1
        while i > 0 and self.arr[i // 2] < x:
            self.arr[i] = self.arr[i // 2]
            i //= 2
            self.arr[i] = x
    def extractMax(self):
        if len(self.arr) == 1:
              return self.arr.pop()
        retval = self.arr[0]
        self.arr[0] = self.arr.pop()
        i = 0
        while 2 * i + 1 < len(self.arr) \
              and self.arr[i] < max(self.arr[2 * i], self.arr[2*i + 1]):
            if self.arr[2 * i] > self.arr[2*i + 1]:
                self.arr[i], self.arr[2 * i] = self.arr[2 * i], self.arr[i]
                i = 2 * i
            else:
                self.arr[i], self.arr[2*i + 1] = self.arr[2*i + 1], self.arr[i] 
                i = 2*i+1
            if 2*i == len(self.arr) - 1 and self.arr[i] < self.arr[2 * i]:
                self.arr[i], self.arr[2 * i] = self.arr[2 * i], self.arr[i]
        return retval
    def print(self):
         print(self.arr)
n = int(input())
heap = Heap()
res = ""
for i in range(n):
    op = input()
    if op == "ExtractMax":
        res += str(heap.extractMax()) + "\n"
    else:
        op, el = op.split()
        el = int(el)
        heap.insert(el)
print(res)
        
        



