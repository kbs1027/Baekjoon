import sys
from collections import deque

DotNum, LineNum, StartNum = map(int, sys.stdin.readline().split())

lst = []
check = []

for i in range(DotNum):
    check.append(0)

def bfs(num):
    Q = deque()
    Q.append(num)
    check[num-1] = 1
    
    while Q:
        s = Q.popleft()
        print(s, end=' ')
        
        for i in range(DotNum):
            if(lst[s-1][i] == 1 and check[i] == 0):
                Q.append(i+1)
                check[i] = 1

def dfs(num):
    print(num, end=' ')
    check[num-1] = 1
    for i in range(DotNum):
        if(lst[num-1][i] == 1 and check[i] == 0):
            dfs(i+1)

for i in range(DotNum):
    line = []
    for i in range(DotNum):
        line.append(0)
    lst.append(line)

for i in range(LineNum):
    a, b = map(int, sys.stdin.readline().split())
    lst[a-1][b-1] = 1
    lst[b-1][a-1] = 1
    
dfs(StartNum)
print()
check = []
for i in range(DotNum):
    check.append(0)
bfs(StartNum)
    