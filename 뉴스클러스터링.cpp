#include <string>
#include <set>
#include <algorithm>
using namespace std;
bool check_validation(char &c1, char &c2, string &output){
    if((('a'<=c1&&c1<='z')||('A'<=c1&&c1<='Z'))&&(('a'<=c2&&c2<='z')||('A'<=c2&&c2<='Z'))){
        output += 'a'<=c1 ? c1-32 : c1;
        output += 'a'<=c2 ? c2-32 : c2;
        return true;
    }
    return false;
}
void makeMultiset(string &s, multiset<string> &ms){
    for(int i = 0; i < s.length()-1;++i){
        string push;
        if(check_validation(s[i],s[i+1],push))
            ms.emplace(push);
    }
}
int solution(string str1, string str2) {
    multiset<string> s1, s2, unions, intersections;
    makeMultiset(str1,s1);
    makeMultiset(str2,s2);
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(unions, unions.begin()));
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(intersections, intersections.begin()));
    return unions.empty()? 65536 : 65536*intersections.size()/unions.size();
}
