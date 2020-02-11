#include <string>
#include <vector>

using namespace std;
vector<int> solution(int n) {
    vector<int> answer;
    for(int i=1;i<=n;i++){
        vector<int> temp;
        temp.assign(answer.begin(),answer.end());
        temp.push_back(0);
        int idx = temp.size()-2;
        while(idx>=0){
            if(temp[idx]==0)
                temp.push_back(1);
            else
                temp.push_back(0);
            idx--;
        }
        swap(temp,answer);
    }
    return answer;
}
