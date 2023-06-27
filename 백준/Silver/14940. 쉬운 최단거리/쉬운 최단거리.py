import sys
from collections import deque

row, col = list(map(int, sys.stdin.readline().split()))

arrival = []
lst = []
check = []
answer = []

def bfs(startRow, startCol):
    Q = deque()
    Q.append([startRow, startCol])
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]
    
    while Q:
        y, x = Q.popleft()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if 0 <= ny < row and 0<= nx < col:
                if check[ny][nx] == False:
                    answer[ny][nx] = answer[y][x] + 1
                    check[ny][nx] = True
                    Q.append([ny,nx])
    
    
for i in range(row):
    line = list(map(int, sys.stdin.readline().split()))
    lst.append(line)
    
for i in range(row):
    line = []
    cline = []
    for j in range(col):
        line.append(0)
        if lst[i][j] == 2:
            arrival.append(i)
            arrival.append(j)
            cline.append(True)
        elif lst[i][j] == 0:
            cline.append(True)
        else:
            cline.append(False)
    answer.append(line)
    check.append(cline)

bfs(arrival[0],arrival[1])
for i in range(row):
    for j in range(col):
        if check[i][j] == False:
            answer[i][j] = -1
for i in range(row):
    print(*answer[i])