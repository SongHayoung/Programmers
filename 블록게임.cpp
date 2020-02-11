#include <string>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <queue>
//3:12:32
using namespace std;
int n;
vector<vector<int>> Board;

bool canFill(int row,int col){
    for(int i=0;i<row;i++)
        if(Board[i][col]!=0) return false;

    return true;
}

bool find(int row, int col, int h, int w){
    int zero = 0;
    int block = -1;
    for(int i=row; i<row + h; i++){
        for(int j=col; j<col+w;j++){
            if(Board[i][j]==0){
                if(!canFill(i,j)) return false;
                if(++zero>2) return false;
            }
            else{
                if(block!=-1&&Board[i][j]!=block) return false;
                block = Board[i][j];
            }
        }
    }
    for(int i=row; i<row+h;i++){
        for(int j=col;j<col+w;j++){
            Board[i][j]=0;
        }
    }
    return true;
}

int solution(vector<vector<int>> board) {
    Board=board;
    n=board.size();
    int answer = 0;
    int cnt = 0;
    do{
        cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<=n-3&&j<=n-2&&find(i,j,3,2)) cnt++;
                else if(i<=n-2&&j<=n-3&&find(i,j,2,3)) cnt++;
            }
        }
        answer+=cnt;
    }while(cnt);

    return answer;
}
