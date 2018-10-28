#******************** INPUT JSON FILE *****************

#{"start":0}

#******************** CODE *****************

import json

def isattack(board,r,c):
    for i in range(r):
        if(board[i][c]==1):
            return True
    
    i=r-1
    j=c-1
    while((i>=0) and (j>=0)):
        if(board[i][j]==1):
            return True
        i=i-1
        j=j-1
    
    i=r-1
    j=c+1
    while((i>=0) and (j<8)):
        if(board[i][j]==1):
            return True
        i=i-1
        j=j+1
    return False
    
def solve(board,row):
    i=0
    while(i<8):
        if(not isattack(board, row, i)):
            board[row][i]=1
            if(row==7):
                return True
            else:
                if(solve(board, row+1)):
                    return True
                else:
                    board[row][i]=0
        i=i+1
    
    if(i==8):
        return False
    
def printboard(board):
    for i in range(8):
        for j in range(8):
            print str(board[i][j])+"  ",
        print "\n"
        
board = [[0 for x in range(8)] for x in range(8)]

if __name__ == '__main__':
    data=[]
    with open('input.json') as f:
        data=json.load(f)
    
    if(data["start"]<0 or data["start"]>7):
        print "Invalid JSON input"
        exit()
    
    board[0][data["start"]]=1
    if(solve(board, 1)):
        print "Queens problem solved!!!"
        print "Board Configuration:"
        printboard(board)
    else:
        print "Queens problem not solved!!!"
        

  