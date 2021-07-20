#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
using tis = tuple<int, int, string>;

map<string, int> visit[1001];
vector<pair<int, int>> adj[1001];
vector<pair<int, int>> rev[1001];
int trap[1001];
int N;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    string state = "";
    N = n;
    memset(trap, -1, sizeof(trap));
    for(int i=0; i<traps.size(); i++){
        state += "0";
        int tg = traps[i];
        trap[tg] = i;
    }
    for(int i=0; i<roads.size(); i++){
        int s = roads[i][0];
        int e = roads[i][1];
        int d = roads[i][2];
        adj[s].push_back({e, d});
        rev[e].push_back({s, d});
    }
    visit[start][state] = -1;
    priority_queue<tis, vector<tis>, greater<tis>> pq;
    pq.push({0, start, state});
    while(!pq.empty()){
        auto [dist, now, nowSt] = pq.top();
        pq.pop();
        if(now == end)  return dist;
        for(int i=0; i<adj[now].size(); i++){
            auto [next, plus] = adj[now][i];
            string nextSt = nowSt;
            bool flag = true;
            if(trap[now] != -1 && nextSt[trap[now]] == '1')     flag = !flag;
            if(trap[next] != -1 && nextSt[trap[next]] == '1')   flag = !flag;
            if(!flag)   continue;
            if(trap[next] != -1){
                if(nextSt[trap[next]] == '0')   nextSt[trap[next]] = '1';
                else                            nextSt[trap[next]] = '0';
            }
            if(visit[next][nextSt] == 0 || visit[next][nextSt] > dist + plus){
                visit[next][nextSt] = dist + plus;
                pq.push({dist+plus, next, nextSt});
            }
        }
        for(int i=0; i<rev[now].size(); i++){
            auto [next, plus] = rev[now][i];
            bool flag = false;
            string nextSt = nowSt;
            if(trap[now] != -1 && nextSt[trap[now]] == '1')     flag = !flag;
            if(trap[next] != -1 && nextSt[trap[next]] == '1')   flag = !flag;
            if(!flag)   continue;
            if(trap[next] != -1){
                if(nextSt[trap[next]] == '0')   nextSt[trap[next]] = '1';
                else                            nextSt[trap[next]] = '0';
            }
            if(visit[next][nextSt] == 0 || visit[next][nextSt] > dist + plus){
                visit[next][nextSt] = dist + plus;
                pq.push({dist+plus, next, nextSt});
            }
        }
    }
    return answer;
}