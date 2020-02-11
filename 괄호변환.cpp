#include <string>
#include <vector>

using namespace std;
bool isPair(string u)
{
    int stat = 0;
    for(int i=0;i<u.length();i++)
    {
        if(u.at(i)=='(')
            stat++;
        else
            stat--;
        if(stat<0)
            return false;
    }
    return true;
}
string solution(string p) {
    string answer = "";
    if(p.length()==0)
        return answer;
    string u;
    string v;
    int stat=0;
    for(int i=0;i<p.length();i++)
    {
        if(p.at(i)=='(')
            stat++;
        else
            stat--;
        if(stat==0)
        {
            stat=i;
            break;
        }
    }
    u=p.substr(0,stat+1);
    v=p.substr(stat+1,p.length()-stat-1);
    if(isPair(u))
    {
        answer+=u;
        answer+=solution(v);
    }
    else
    {
        answer+='(';
        answer+=solution(v);
        answer+=')';
        u.erase(u.end()-1);
        u.erase(u.begin());
        for(int i=0;i<u.length();i++)
        {
            if(u.at(i)=='(')
                answer+=')';
            else
                answer+='(';
        }
    }

    return answer;
}
