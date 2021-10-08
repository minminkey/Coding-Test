//BFS
#include <string>
#include <tuple>
#include <vector>
#include <queue>

#define tiii tuple<int, int, int, int>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int cost[26][26];
int N;

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cost[i][j] = 0x3f3f3f3f;
        }
    }
    cost[0][0] = 0;
    queue<tiii> q;
    q.push({0,0,1,0});
    q.push({0,0,2,0});
    while(!q.empty()){
        auto [r, c, d, now] = q.front();
        q.pop();
        for(int nd=0; nd<4; nd++){
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            if(nr<0||nc<0||nr>=N||nc>=N)    continue;
            if(board[nr][nc] == 1)          continue;
            int plus = 100;
            if((nd+1)%4 == d || (d+1)%4 == nd)  plus += 500;
            int next = now + plus;
            if(cost[nr][nc] + 600 < next)         continue;
            if(cost[nr][nc]>next)   cost[nr][nc] = next;
            q.push({nr, nc, nd, next});
        }
    }
    answer = cost[N-1][N-1];
    return answer;
}