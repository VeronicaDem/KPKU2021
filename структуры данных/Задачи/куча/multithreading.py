# put your python code here
from copy import deepcopy
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
        while i > 0 and self.arr[i // 2] > x:
            self.arr[i] = self.arr[i // 2]
            i //= 2
            self.arr[i] = x
    def extractMin(self):
        if len(self.arr) == 1:
              return self.arr.pop()
        retval = self.arr[0]
        self.arr[0] = self.arr.pop()
        i = 0
        while 2 * i + 1 < len(self.arr) \
              and self.arr[i] < min(self.arr[2 * i], self.arr[2*i + 1]):
            if self.arr[2 * i] < self.arr[2*i + 1]:
                self.arr[i], self.arr[2 * i] = self.arr[2 * i], self.arr[i]
                i = 2 * i
            else:
                self.arr[i], self.arr[2*i + 1] = self.arr[2*i + 1], self.arr[i] 
                i = 2*i+1
            if 2*i == len(self.arr) - 1 and self.arr[i] > self.arr[2 * i]:
                self.arr[i], self.arr[2 * i] = self.arr[2 * i], self.arr[i]
        return retval
    def print(self):
         print(self.arr)
class Process():
    def __init__(self, nomer, time_process, start_time):
        self.time_process = time_process
        self.nomer = nomer
        self.start_time = start_time
    def isFree(self, time):
        return self.start_time + self.time_process < time
    def __lt__(self, other):
        return self.start_time < other.start_time
    def __gt__(self, other):
        return self.start_time > other.start_time

n, m = list(map(int, input().split()))
tasks_times = []
for i in range(m):
    tasks_times.append(float(input()))
start_time = 1
heap = Heap()
res = ""
for i in range(m):
    if i < n:
       p = Process(i, tasks_times[i], start_time)
       heap.insert(p)
       res += str(start_time) + " " + str(i + 1) + " " + str(i + 1) + "\n"

    else:
        to_insert = []
        p = deepcopy(heap.extractMin())
        to_insert.append(p)
        while not p.isFree(start_time + tasks_times[i]):
            p = deepcopy(heap.extractMin())
            to_insert.append(p)
        
        start_time += 1
        p.start_time = start_time
        p.time_process = tasks_times[i]
        heap.insert(p)
        res += str(start_time) + " " + str(p.nomer + 1) + " " + str(i + 1) + "\n"
        for el in to_insert:
            heap.insert(el)
print(res)

            


       



        
        




