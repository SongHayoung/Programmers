#include <string>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> map(n+1,vector<int>(n+1,0));
    bool visit[n+1];
    memset(visit,false,sizeof(visit));
    for(int i=0;i<edge.size();i++){
        map[edge[i][0]][edge[i][1]]=1;
        map[edge[i][1]][edge[i][0]]=1;
    }
    queue<int> q;
    q.push(1);
    visit[1]=true;
    map[1][1]=0;
    int dist = 0;
    int answer = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if((map[cur][i]==1)&&!visit[i]){
                q.push(i);
                map[i][i]=map[cur][cur]+1;
                visit[i]=true;
                if(dist==map[i][i]){
                    answer+=1;
                }
                else if(dist<map[i][i]){
                    answer = 1;
                    dist = map[i][i];
                }
            }
        }
        
    }
    return answer;
}
