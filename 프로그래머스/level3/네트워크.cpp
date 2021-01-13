#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent;
vector<int> vi;

void dfs(vector<vector<int>> computers, int p, int c){
    for(int i=0; i<computers[c].size(); i++){
        if(computers[c][i]==1){
            if(vi[i]==1)    continue;
            parent[i] = p;
            vi[i] = 1;
            dfs(computers, p, i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 1;
    for(int i=0; i<n; i++){
        parent.push_back(i);
        vi.push_back(0);
    }
    for(int i=0; i<n; i++){
        dfs(computers, i, i);
    }
    sort(parent.begin(), parent.end());
    parent.erase(unique(parent.begin(), parent.end()), parent.end());
    return parent.size();
}