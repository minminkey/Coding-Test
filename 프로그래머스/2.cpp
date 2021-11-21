#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int time, int gold, vector<vector<int>> upgrade) {
    int answer = -1;
    int maxPrice = 0;
    vector<tuple<int, int, int>> limit;
    int now = 0;
    int money = 0;
    limit.push_back({0,0,upgrade[0][1]});
    for(int i=1; i<upgrade.size(); i++){
        int want = upgrade[i][0];
        int per = upgrade[i-1][1];
        while(money<want){
            now+=per;
            money += gold;
        }
        limit.push_back({now, money-want, upgrade[i][1]});
        money -= want;
    }
    for(int i=0; i<limit.size(); i++){
        auto [now, balance, per] = limit[i];
        if(now>time){
            continue;
        }
        else if(now==time){
            answer = max(answer, balance);
            continue;
        }
        int plus = ((time-now)/per)*gold;
        answer = max(answer, balance + plus);
    }
    return answer;
}