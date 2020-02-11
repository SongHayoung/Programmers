#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int>forCalcCopy;

    for(int i=0; i<commands.size(); i++)
    {
        forCalcCopy.clear();
        forCalcCopy.assign(array.begin()+(commands[i][0]-1), array.begin()+(commands[i][1])); 
        sort(forCalcCopy.begin(), forCalcCopy.end());
        answer.push_back(forCalcCopy[commands[i][2]-1]);

    }

    return answer;
}
