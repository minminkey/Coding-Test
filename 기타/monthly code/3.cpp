#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[300001];
vector<long long> weight;
long long cnt = 0;

void dfs(int parent, int now){
    for(int i=0; i<edge[now].size(); i++){
        int next = edge[now][i];
        if(next==parent)    continue;
        dfs(now, next);
    }
    if(parent==-1)  return;
    cnt += abs(weight[now]);
    weight[parent] += weight[now];
    weight[now] = 0;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    for(int i=0; i<a.size(); i++){
        weight.push_back(a[i]);
    }
    for(int i=0; i<edges.size(); i++){
        int s = edges[i][0];
        int e = edges[i][1];
        edge[s].push_back(e);
        edge[e].push_back(s);
    }
    dfs(-1, 0);
    if(weight[0]!=0)    answer = -1;
    else                answer = cnt;
    return answer;
}