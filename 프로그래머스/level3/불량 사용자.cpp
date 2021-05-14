#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, vector<int>> mp;
map<string, int> mp2;
int visit[10];
int N;
int ans = 0;

void dfs(string id, string now, int idx, int i){
    if(idx>=id.length()){
        mp[now].push_back(i);
        return;
    }
    dfs(id, now+"*", idx+1, i);
    dfs(id, now+id[idx], idx+1, i);
}
void dfs2(vector<string> &id, int idx){
    if(idx>=id.size()){
        string tmp = "";
        for(int i=0; i<N; i++){
            if(visit[i]==0) tmp += "0";
            else            tmp += "1";
        }
        mp2[tmp]++;
        if(mp2[tmp]==1) ans++;
        return;
    }
    vector<int> now = mp[id[idx]];
    for(int i=0; i<now.size(); i++){
        if(visit[now[i]]==0){
            visit[now[i]] = 1;
            dfs2(id, idx+1);
            visit[now[i]] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 1;
    N = user_id.size();
    for(int i=0; i<user_id.size(); i++){
        dfs(user_id[i], "", 0, i);
    }
    dfs2(banned_id, 0);
    answer = ans;
    return answer;
}