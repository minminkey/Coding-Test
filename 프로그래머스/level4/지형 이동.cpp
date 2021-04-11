#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, H;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int visit[301][301] = {0,};
int parent[90001] = {0,};

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    parent[x] = y;
    return 1;
}

void fillLand(vector<vector<int>> &land, int r, int c, int idx){
    queue<pair<int, int>> q;
    visit[r][c] = idx;
    q.push({r,c});
    while(!q.empty()){
        auto [nowR, nowC] = q.front();
        int value = land[nowR][nowC];
        q.pop();
        for(int i=0; i<4; i++){
            int nr = nowR + dr[i];
            int nc = nowC + dc[i];
            if(nr<0||nc<0||nr>=N||nc>=N)    continue;
            int gap = abs(value - land[nr][nc]);
            if(visit[nr][nc]!=0||gap>H)    continue;
            visit[nr][nc] = idx;
            q.push({nr, nc});
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    N = land.size();
    H = height;
    int idx = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visit[i][j]==0){
                fillLand(land, i, j, idx);
                
                idx++;
            }
        }
    }
    for(int i=0; i<=idx; i++){
        parent[i] = i;
    }
    priority_queue<tuple<int, int, int>> pq;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int value = visit[i][j];
            for(int k=1; k<3; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr<0||nc<0||nr>=N||nc>=N)    continue;
                if(visit[nr][nc]==value)        continue;
                int gap = abs(land[i][j] - land[nr][nc]);
                pq.push({-gap, value, visit[nr][nc]});
            }
        }
    }
    int cnt = 0;
    while(!pq.empty()){
        if(cnt>=idx-1){
            break;
        }
        auto [c, x, y] = pq.top();
        pq.pop();
        if(merge(x, y)){
            answer -= c;
            cnt++;
        }
    }
    return answer;
}