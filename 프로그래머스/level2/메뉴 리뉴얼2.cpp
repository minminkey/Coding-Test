#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

map<string, int> candidate;
vector<vector<char>> orderList;
vector<string> res[11];
int cnt[11];

void dfs(int idx, int s, string now, int len){
    if(now.length() == len){
        candidate[now]++;
        if(candidate[now]<2)    return;
        if(cnt[len]<candidate[now]){
            cnt[len] = candidate[now];
            res[len].clear();
            res[len].push_back(now);
        }
        else if(cnt[len]==candidate[now]){
            res[len].push_back(now);
        }
        return;
    }
    for(int i=s; i<orderList[idx].size(); i++){
        string next = now + orderList[idx][i];
        dfs(idx, i+1, next, len);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0; i<orders.size(); i++){
        vector<char> tmp;
        for(int j=0; j<orders[i].length(); j++){
            tmp.push_back(orders[i][j]);
        }
        sort(tmp.begin(), tmp.end());
        orderList.push_back(tmp);
    }
    for(int i=0; i<orderList.size(); i++){
        for(int k=2; k<=orderList[i].size(); k++){
            dfs(i, 0, "", k);
        }
    }
    for(int i=0; i<course.size(); i++){
        for(int j=0; j<res[course[i]].size(); j++){
            answer.push_back(res[course[i]][j]);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}