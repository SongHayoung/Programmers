#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<double,double>> list;

void anal(vector<string> lines){
    for(int i=0;i<lines.size();i++){
        string times;
        long double t = ((lines[i][11]-'0')*10+(lines[i][12]-'0'))*3600;
        long double m = ((lines[i][14]-'0')*10+(lines[i][15]-'0'))*60;
        long double s = ((lines[i][17]-'0')*10+(lines[i][18]-'0'));
        long double u = ((double)(lines[i][20]-'0')/10) +
                        ((double)(lines[i][21]-'0')/100) +
                        ((double)(lines[i][22]-'0')/1000);
        long double end_time = t+m+s+u;
        for(int j=24;j<=lines[i].length()-2;j++)
            times.push_back(lines[i][j]);
        long double start_time = end_time - stod(times) + 0.001;
        list.push_back(make_pair(start_time,end_time));
    }
}
int solution(vector<string> lines) {
    if(lines.size()==0)
        return 0;
    else if(lines.size()==1)
        return 1;
    anal(lines);
    int answer = 0;
    for(int i=0;i<list.size();i++){
        int cnt = 0;
        long double comp_start = list[i].second;
        long double comp_end = comp_start+0.9995;
        cout.precision(11);
        for(int j=0;j<list.size();j++){
            if(comp_start<=list[j].second && list[j].second<=comp_end){
                cnt++;
            }
            else if(comp_start<=list[j].first && list[j].first<=comp_end){
                cnt++;
            }
            else if(list[j].first<=comp_start&&comp_end<=list[j].second)
                cnt++;
        
        }
        answer = max(answer,cnt);
    }
    return answer;
}
