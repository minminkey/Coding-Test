#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

#define tiii tuple<int, int, int>

using namespace std;

int N;
vector<int> num;
int minSum = 0x3f3f3f3f;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void go(vector<vector<int>> &board, int &r, int &c, int d){
    int nr = r + dr[d];
    int nc = c + dc[d];
    while(nr>=0&&nc>=0&&nr<N&&nc<N){
        r = nr;
        c = nc;
        if(board[nr][nc] != 0)  return;
        nr = r + dr[d];
        nc = c + dc[d];
    }
}

int findCard(vector<vector<int>> &board, int t, int &r, int &c){
    if(board[r][c] == t){
        board[r][c] = 0;
        return 0;
    }
    queue<tiii> q;
    q.push({r, c, 0});
    vector<vector<int>> visit;
    for(int i=0; i<N; i++){
        vector<int> tmp;
        for(int j=0; j<N; j++){
            tmp.push_back(0);
        }
        visit.push_back(tmp);
    }
    while(!q.empty()){
        auto [nowR, nowC, cnt] = q.front();
        q.pop();
        for(int d=0; d<4; d++){
            int nr = nowR;
            int nc = nowC;
            go(board, nr, nc, d);
            if(nr<0||nc<0||nr>=N||nc>=N||visit[nr][nc] == 1)    continue;
            if(board[nr][nc] == t){
                board[nr][nc] = 0;
                r = nr;
                c = nc;
                return cnt + 1;
            }
            q.push({nr, nc, cnt+1});
            visit[nr][nc] = 1;
        }
        for(int d=0; d<4; d++){
            int nr = nowR + dr[d];
            int nc = nowC + dc[d];
            if(nr<0||nc<0||nr>=N||nc>=N||visit[nr][nc] == 1)    continue;
            if(board[nr][nc] == t){
                board[nr][nc] = 0;
                r = nr;
                c = nc;
                return cnt + 1;
            }
            q.push({nr, nc, cnt+1});
            visit[nr][nc] = 1;
        }
    }
    return -100;
}

void findAll(vector<vector<int>> &board, int r, int c, int sum, int cnt){
    if(cnt == num.size()){
        if(sum<minSum)  minSum = sum;
        return;
    }
    for(int i=0; i<num.size(); i++){
        if(num[i] == 0) continue;
        vector<vector<int>> copy = board;
        int t = num[i];
        num[i] = 0;
        int nr = r;
        int nc = c;
        int nsum = sum;
        nsum += findCard(copy, t, nr, nc);
        nsum += findCard(copy, t, nr, nc);
        findAll(copy, nr, nc, nsum, cnt+1);
        num[i] = t;
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    N = board.size();
    int tmp[7] = {0, };
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tmp[board[i][j]]++;
        }
    }
    for(int i=1; i<7; i++){
        if(tmp[i]>0)    num.push_back(i);
    }
    findAll(board, r, c, 0, 0);
    answer = minSum + num.size()*2;
    return answer;
}