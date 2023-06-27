import sys
sys.setrecursionlimit(10**7)

blockNum = 0
blockNumzero = 0

lst = []

def slice_block(rowFirst, rowLast, colFirst, colLast):
    global blockNum
    global lst
    check = True
    if rowLast - rowFirst == 1:
        if lst[rowFirst][colFirst] == 1:
            blockNum += 1
        return 0
    rowblock = int((rowLast - rowFirst)/2)
    colblock = int((colLast - colFirst)/2) 
    for i in range(rowFirst, rowLast):
        for j in range(colFirst, colLast):
            if lst[i][j] == 0:
                check = False
                break
    if check:
        blockNum +=1
        return 0
    
    else:
        slice_block(rowFirst, rowFirst+rowblock, colFirst, colFirst+colblock)
        slice_block(rowFirst, rowFirst+rowblock, colFirst+colblock, colLast)
        slice_block(rowFirst+rowblock, rowLast, colFirst, colFirst+colblock)
        slice_block(rowFirst+rowblock, rowLast, colFirst+colblock, colLast)

def slice_blockz(rowFirst, rowLast, colFirst, colLast):
    global blockNumzero
    global lst
    check = True
    if rowLast - rowFirst == 1:
        if lst[rowFirst][colFirst] == 0:
            blockNumzero += 1
        return 0
    rowblock = int((rowLast - rowFirst)/2)
    colblock = int((colLast - colFirst)/2) 
    for i in range(rowFirst, rowLast):
        for j in range(colFirst, colLast):
            if lst[i][j] == 1:
                check = False
                break
    if check:
        blockNumzero +=1
        return 0
    
    else:
        slice_blockz(rowFirst, rowFirst+rowblock, colFirst, colFirst+colblock)
        slice_blockz(rowFirst, rowFirst+rowblock, colFirst+colblock, colLast)
        slice_blockz(rowFirst+rowblock, rowLast, colFirst, colFirst+colblock)
        slice_blockz(rowFirst+rowblock, rowLast, colFirst+colblock, colLast)

num = int(input())
for i in range(num):
    lst.append(list(map(int, sys.stdin.readline().split())))

slice_block(0,num, 0, num)
slice_blockz(0,num, 0, num)
print(blockNumzero)
print(blockNum)

