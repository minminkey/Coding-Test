#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define tiii tuple<int, int, int>

using namespace std;

char map[31][31];
int ck[31][31];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N;

void infection(int R, int C){
    int visit[31][31] = {0,};
    queue<tiii> q;
    q.push({R, C, 0});
    while(!q.empty()){
        auto [r, c, dist] = q.front();
        q.pop();
        if(dist>3) continue;
        if((dist<=3&&map[r][c]=='N')||(dist<=2&&map[r][c]=='M'))    ck[r][c] = 1;
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<0||nc<0||nr>=N||nc>=N)    continue;
            if(visit[nr][nc] == 1)  continue;
            visit[nr][nc] = 1;
            q.push({nr, nc, dist+1});
        }
    }
}

int solution(vector<string> seat) {
    int answer = 0;
    N = seat.size();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            map[i][j] = seat[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 'C') infection(i, j);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(ck[i][j] == 1) answer++;
        }
    }
    return answer;
}