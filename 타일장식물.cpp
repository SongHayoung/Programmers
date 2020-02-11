#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    vector<long long> answer(N+1,0);
    answer[0]=1;
    answer[1]=1;
    for(int i=2;i<=N;i++){
        answer[i]=answer[i-1]+answer[i-2];
    }
    return answer[N]*2+answer[N-1]*2;
}
