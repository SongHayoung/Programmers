#include <vector>
#include <iostream>
using namespace std;
int answer = 1;
int INFO[10];
int SIZE, P, L;
void DFS(vector<int> &priorities, int _P,int start){
    if(_P==P){
        while(start!=L){
            if(priorities[start]==P)
                ++answer;
            start = (start+1)%SIZE;
        }
        return ;
    }
    if(INFO[_P]==0){
        DFS(priorities,_P-1,start);
        return ;
    }
    answer += INFO[_P];
    for(int i=0;i<SIZE;i++){
        start = start - 1 == -1 ? SIZE-1 : start -1;
        if(priorities[start]==_P) {
            DFS(priorities,_P-1,start);
            break;
        }
    }
}

int solution(vector<int> priorities, int location) {
    SIZE = priorities.size();
    P = priorities[location];
    L = location;
    vector<int> p(100);
    int index = 0;
    for(int i=0;i<SIZE;i++)
        if(priorities[i]>=P) {
            ++INFO[priorities[i]];
            p[index++] = priorities[i];
        }
        else if(i<location)
            --L;
    SIZE = p.size();
    DFS(p,9,0);
    return answer;
}
