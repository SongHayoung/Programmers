#include <math.h>
#include <algorithm>
using namespace std;

int DFS(int N,int number,long long cur,int used){
    if(used>=9)
        return 987654321;
    if(cur==number)
        return used;
    int ans = 987654321;
    int a = 0;
    for(int i=1;i<(9-used);i++){
        a += pow(10,i-1);
        int need = N*a;

        ans = min(ans,DFS(N,number,cur+need,used+i));
        ans = min(ans,DFS(N,number,cur-need,used+i));
        ans = min(ans,DFS(N,number,cur/need,used+i));
        ans = min(ans,DFS(N,number,cur*need,used+i));
    }
    return ans;
}

int solution(int N,int number){
    int ans = DFS(N,number,0,0);
    ans = ans > 8 ? -1 : ans;
    return ans;
}
