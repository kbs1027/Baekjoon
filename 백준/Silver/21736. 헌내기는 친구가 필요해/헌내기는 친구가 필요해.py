import sys 
from collections import deque

a, b = map(int,sys.stdin.readline().split())

lst = []
check = []
start = []

def bfs(start):
    Q = deque()
    Q.append(start)
    dx = [0, 0, 1, -1]
    dy = [1, -1 ,0 ,0]
    count = 0
    
    while Q:
        n, m = Q.popleft()
        check[n][m] = True
        if lst[n][m] == 'P':
            count += 1
        
        for i in range(4):
            y = n + dy[i]
            x = m + dx[i]
            if(0 <= x < b and 0 <= y < a):
                if(check[y][x] == False):
                    Q.append([y,x])
                    check[y][x] = True
                    
    return count

for i in range(a):
    line = []
    cline = []
    string = str(input())
    for j in range(b):
        line.append(string[j])
        if string[j] == 'X':
            cline.append(True)
        else:
            if string[j] == 'I':
                start.append(i)
                start.append(j)
            cline.append(False)
    lst.append(line)
    check.append(cline)
    
answer = bfs(start)
if answer == 0:
    print('TT')
else:
    print(answer)
