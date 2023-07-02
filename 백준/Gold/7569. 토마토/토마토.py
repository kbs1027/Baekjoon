import sys 
from collections import deque

column, row, height = map(int,sys.stdin.readline().split())

lst = []
check = []
start = []

def bfs(start):
    global column, row, height
    global lst, check
    Q = deque()
    for i in range(len(start)):
        Q.append(start[i])
    dx = [0, 0, 0, 0, 1, -1]
    dy = [0, 0, 1, -1 ,0 ,0]
    dz = [1, -1, 0, 0, 0, 0]
    max = 0
    z,y,x,count = 0, 0, 0, 0
    
    while Q:
        z, y, x,count  = Q.popleft()
        check[z][y][x] = True
        
        for i in range(6):
            az = z + dz[i]
            ay = y + dy[i]
            ax = x + dx[i]
            if(0 <= ax < column and 0 <= ay < row and 0<= az < height):
                if(check[az][ay][ax] == False and lst[az][ay][ax] == 0):
                    Q.append([az,ay,ax,count+1])
                    lst[az][ay][ax] += 1
                    check[az][ay][ax] = True
                    if max < count+1:
                        max = count+1
                    
    return count

for i in range(height):
    line = []
    cline = []
    for j in range(row):
        line.append(list(map(int, sys.stdin.readline().split())))
        csubline = []
        for k in range(column):
            if line[j][k] == -1:
                csubline.append(True)
            elif line[j][k] == 0:
                csubline.append(False)
            else:
                csubline.append(True)
                start.append([i,j,k,0])
        cline.append(csubline)
    lst.append(line)
    check.append(cline)

answer = bfs(start)
for i in range(height):
    for j in range(row):
        for k in range(column):
            if lst[i][j][k] == 0:
                answer = -1
print(answer)
