#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int changeToSecond(string s){
    int k = 3600;
    int second = 0;
    string tmp = "";
    for(int i=0; i<s.length(); i++){
        if(s[i]==':'){
            second += stoi(tmp)*k;
            tmp = "";
            k /= 60;
        }
        else{
            tmp += s[i];
        }
    }
    second += stoi(tmp)*k;
    return second;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    long long total[361000] = {0, };
    int play_second = changeToSecond(play_time);
    int adv_second = changeToSecond(adv_time);
    vector<int> start;
    vector<int> end;
    for(int i=0; i<logs.size(); i++){
        string tmp = "";
        start.push_back(changeToSecond(logs[i].substr(0,8)));
        end.push_back(changeToSecond(logs[i].substr(9,8)));
    }
    for(int i=0; i<start.size(); i++){
        total[start[i]]++;
        total[end[i]]--;
    }
    for(int i=1; i<play_second; i++){
        total[i] += total[i-1];
    }
    long long sum = 0;
    long long maxSum = 0;
    queue<int> q;
    int ansSecond = 0;
    for(int i=0; i<adv_second; i++){
        sum += total[i];
        q.push(total[i]);
    }
    maxSum = sum;
    for(int i=adv_second; i<play_second; i++){
        sum += total[i];
        sum -= q.front();
        q.push(total[i]);
        q.pop();
        if(maxSum<sum){
            ansSecond = i-adv_second+1;
            maxSum = sum;
        }
    }
    string tinfo[3];
    tinfo[0] = to_string(ansSecond/3600);
    ansSecond %= 3600;
    tinfo[1] = to_string(ansSecond/60);
    tinfo[2] = to_string(ansSecond%60);    
    for(int i=0; i<3; i++){
        if(tinfo[i].length()<2){
            answer += "0";
        }
        answer += tinfo[i] + ":";
    }
    answer.pop_back();
    return answer;
}