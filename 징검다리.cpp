#include <vector>
#include <algorithm>
using namespace std;
//정답이 아니나 정답으로 인정되는 코드
/*
 inline bool is_possible(vector<int>& rocks, int &stnd, int &n, int &dis){
 int removed = 0, prev = 0, i;
 for(i=0;i<rocks.size();i++){
 if(rocks[i]-prev<stnd)
 ++removed;
 else
 prev = rocks[i];
 }
 if((dis-rocks[i])<dis)
 return (removed+1)<=n;
 return removed<=n;
 }*/
//정답코드
bool is_possible(vector<int>& rocks, int &stnd, int &n, int &dis){
    int removed = 0, prev = 0, i;
    for(i=0;i<rocks.size();i++){
        if(rocks[i]-prev<stnd){
            ++removed;
        }
        else
            prev = rocks[i];
    }
    if((dis-rocks[i-1])<stnd)
        return ++removed<=n;
    return removed<=n;
}
int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(),rocks.end());
    int lo = 1, hi = distance, mid;
    while(lo+1<hi){
        mid = (lo+hi)/2;
        if(is_possible(rocks,mid,n,distance))
            lo = mid;
        else
            hi = mid;
    }
    return is_possible(rocks,lo,n,distance) ?lo : hi;
}
