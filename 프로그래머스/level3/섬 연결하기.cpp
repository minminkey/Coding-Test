#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];
bool cmp(vector<int> a, vector<int> b){
    if(a[2]==b[2])  return a[0]<b[0];
    return a[2]<b[2];
}
int findParent(int a){
    if(a == parent[a])  return a;
    else    return a = findParent(parent[a]);
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;
    for(int i=0; i<n; i++)  parent[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    for(int i=0; i<costs.size(); i++){
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        int sparent = findParent(start);
        int eparent = findParent(end);
        if(sparent!=eparent){
            answer += cost;
            parent[sparent] = eparent;
        }
    }
    return answer;
}