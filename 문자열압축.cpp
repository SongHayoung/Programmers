#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i=1;i<=s.length()/2;i++)
    {
        string new_s;
        int idx = 0;

        while(1)
        {
            string comp=s.substr(idx,i);
            int cnt = 0;
            while(comp.compare(s.substr(idx,i))==0)
            {
                cnt++;
                idx+=i;
            }
            if(cnt>1)
            {
                new_s+=to_string(cnt);
                new_s+=comp;
            }
            else {
                new_s+=comp;
            }
            if(idx+i>=s.length()) {
                new_s+=s.substr(idx,s.length()-idx);
                break;
            }
        }
        answer = min(answer,(int)new_s.length());
    }

    return answer;
}
