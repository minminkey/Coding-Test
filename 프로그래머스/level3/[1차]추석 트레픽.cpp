#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)  return a.second < b.second;
    return a.first < b.first;
}
int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> Times;
    priority_queue <int, vector<int>, greater<>> traffic;
    int time = 0;
    int Size = lines.size();
    for(int i=0; i<Size; i++){
        int hours = stoi(lines[i].substr(11,2));
        int minutes = stoi(lines[i].substr(14,2));
        int seconds = stoi(lines[i].substr(17,2));
        int ms = stoi(lines[i].substr(20,3));
        int fT = stoi(lines[i].substr(24,1))*1000;
        string s = lines[i].substr(25,1);
        if(s.compare(".")==0){
            int tmp2 = stoi(lines[i].substr(26,lines[i].size()-26));
            fT += tmp2;
        }
        int endTime = 1000*(3600*hours + 60*minutes + seconds) + ms;
        int startTime = endTime - fT + 1;
        if(startTime<0) startTime = 0;
        Times.push_back({startTime, endTime});
    }
    sort(Times.begin(), Times.end(), cmp);
    for(int i=0; i<Size; i++){
        if(traffic.empty()){
            traffic.push(Times[i].second);
        }
        else{
            time = traffic.top();
            while(Times[i].first-999>traffic.top()){
                traffic.pop();
                if(traffic.empty()) break;
            }
            traffic.push(Times[i].second);
        }
        if(answer<traffic.size())   answer = traffic.size();
    }
    if(Times.size()==1) return 1;
    return answer;
}