#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <string.h>
using namespace std;

int n, m, fuel;
int nowR, nowC;
int mp[21][21];
int visit[21][21];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<pair<int, int>> tg;


int findPasenger(){
    memset(visit, 0, sizeof(visit));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(nowR, nowC, 0));
    visit[nowR][nowC] = 1;
    if(mp[nowR][nowC]!=0&&mp[nowR][nowC]!=1){
        return mp[nowR][nowC];
    }
    int tr = 100;
    int tc = 100;
    int tdist = 1000;
    while(!q.empty()){
        auto [r, c, dist] = q.front();
        q.pop();
        if(dist+1>fuel)     continue;
        if(dist+1>tdist)    continue;
        for(int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr<0||nc<0||nr>=n||nc>=n||mp[nr][nc]==1||visit[nr][nc]==1)    continue;
            visit[nr][nc] = 1;
            if(mp[nr][nc]!=0){
                if(tdist>dist+1){
                    tr = nr;
                    tc = nc;
                    tdist = dist+1;
                    continue;
                }
                else if(tdist==dist+1){
                    if(tr>nr){
                        tr = nr;
                        tc = nc;
                    }
                    else if(tr==nr){
                        if(tc>nc){
                            tc = nc;
                        }
                    }
                }
                continue;
            }
            q.push(make_tuple(nr, nc, dist+1));
        }
    }
    if(tdist==1000){
        return -1;
    }
    nowR = tr;
    nowC = tc;
    fuel -= tdist;
    return mp[nowR][nowC];
}

int findTarget(int tr, int tc){
    memset(visit, 0, sizeof(visit));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(nowR, nowC, 0));
    visit[nowR][nowC] = 1;
    while(!q.empty()){
        auto [r, c, dist] = q.front();
        q.pop();
        if(dist+1>fuel) continue;
        for(int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr<0||nc<0||nr>=n||nc>=n||mp[nr][nc]==1||visit[nr][nc]==1)    continue;
            visit[nr][nc] = 1;
            if(nr==tr&&nc==tc){
                nowR = nr;
                nowC = nc;
                fuel -= dist+1;
                return dist+1;
            }
            q.push(make_tuple(nr, nc, dist+1));
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>fuel;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mp[i][j];
        }
    }
    cin>>nowR>>nowC;
    nowR--;
    nowC--;
    tg.push_back({-1,-1});
    tg.push_back({-1,-1});
    for(int i=2; i<=m+1; i++){
        int r, c, nr, nc;
        cin>>r>>c>>nr>>nc;
        mp[r-1][c-1] = i;
        tg.push_back({nr-1, nc-1});
    }
    for(int i=0; i<m; i++){
        int pasenger = findPasenger();
        if(pasenger==-1){
            cout<<-1<<endl;
            return 0;
        }
        mp[nowR][nowC] = 0;
        auto [r, c] = tg[pasenger];
        int dist = findTarget(r, c);
        if(dist==-1){
            cout<<-1<<endl;
            return 0;
        }
        fuel += dist*2;
    }
    cout<<fuel<<'\n';
    return 0;
}
