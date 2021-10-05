#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> edge[101];
int child[101];
int N;
int ans = 0x3f3f3f3f;

int dfs(int s, vector<int> visit){
    for(int i=0; i<edge[s].size(); i++){
        int e = edge[s][i];
        if(visit[e] == 1)   continue;
        visit[e] = 1;
        child[s] += dfs(e, visit);
        visit[e] = 0;
    }
    int parent = N-child[s]-1;
    ans = min(ans, abs(parent - child[s]-1));
    return child[s]+1;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    N = n;
    for(int i=0; i<wires.size(); i++){
        int s = wires[i][0];
        int e = wires[i][1];
        edge[s].push_back(e);
        edge[e].push_back(s);
    }
    vector<int> visit(101);
    visit[1] = 1;
    dfs(1, visit);
    answer = ans;
    return answer;
}