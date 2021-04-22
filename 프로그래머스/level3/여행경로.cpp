#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int flag = 0;
int n;
vector<string> ans;
map<string, vector<string>> mp;
map<string, vector<int>> visit;

void dfs(string now, vector<string> pre, int cnt){
    if(flag == 1)   return;
    if(cnt == n){
        ans = pre;
        flag = 1;
        return;
    }
    for(int i=0; i<mp[now].size(); i++){
        if(visit[now][i]==1)    continue;
        visit[now][i] = 1;
        string next = mp[now][i];
        pre.push_back(next);
        dfs(next, pre, cnt+1);
        pre.pop_back();
        visit[now][i] = 0;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    n = tickets.size();
    for(int i=0; i<n; i++){
        string s = tickets[i][0];
        string e = tickets[i][1];
        if(mp.find(s)==mp.end()){
            vector<string> tmp;
            vector<int> tmp2;
            tmp.push_back(e);
            tmp2.push_back(0);
            mp[s] = tmp;
            visit[s] = tmp2;
        }
        else{
            mp[s].push_back(e);
            visit[s].push_back(0);
        }
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        sort((*it).second.begin(), (*it).second.end());
    }
    string now = "ICN";
    answer.push_back(now);
    dfs(now, answer, 0);
    answer = ans;
    return answer;
}