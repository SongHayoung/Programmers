#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp(501,vector<int>(501,-1));
vector<vector<int>> t;
int calc(int x, int y,int m){
    if(x<0||y<0||x>y||y>=m)
        return 0;
    int &ret = dp[y][x];
    if(ret!=-1)
        return ret;
    ret = 0;
    ret = max(calc(x,y+1,m),calc(x+1,y+1,m))+t[y][x];
    return ret;
}

int solution(vector<vector<int>> triangle) { 
    t = triangle;
    return   calc(0,0,triangle.size());
}
