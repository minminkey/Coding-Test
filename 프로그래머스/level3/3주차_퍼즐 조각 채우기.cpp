//구현
#include <string>
#include <queue>
#include <vector>
#include <tuple>
#include <iostream>

#define vvi vector<vector<int>>

using namespace std;

vector<vvi> blist;
vector<vvi> tlist;
vector<int> use;
int visit[2][51][51];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int N;

vvi spin(vvi now){
    int R = now.size();
    int C = now[0].size();
    vvi res;
    for(int c=0; c<C; c++){
        vector<int> tmp;
        for(int r=R-1; r>=0; r--){
            tmp.push_back(now[r][c]);
        }
        res.push_back(tmp);
    }
    return res;
}

tuple<int, int, int, int> find(vvi &board, int R, int C, int type){
    int up, down, left, right;
    down = up = R;
    left = right = C;
    queue<pair<int, int>> q;
    q.push({R,C});
    visit[type][R][C] = 1;
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int d=0; d<4; d++){
            int nr = r+dr[d];
            int nc = c+dc[d];
            if(nr<0||nc<0||nr>=N||nc>=N)    continue;
            if(visit[type][nr][nc] == 1 || board[nr][nc] == 1)          continue;
            visit[type][nr][nc] = 1;
            if(nr<up)       up = nr;
            if(nr>down)     down = nr;
            if(nc<left)     left = nc;
            if(nc>right)    right = nc;
            q.push({nr, nc});
        }
    }
    return {up, down, left, right};
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    N = table.size();
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(game_board[r][c] == 1 || visit[0][r][c])   continue;
            auto [up,down,left,right] = find(game_board, r, c, 0);
            vvi res;
            for(int i=up; i<=down; i++){
                vector<int> tmp;
                for(int j=left; j<=right; j++){
                    tmp.push_back(game_board[i][j]);
                }
                res.push_back(tmp);
            }
            blist.push_back(res);
        }
    }
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(table[r][c] == 0)    table[r][c] = 1;
            else                    table[r][c] = 0;
        }
    }
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(table[r][c] == 1 || visit[1][r][c])   continue;
            auto [up,down,left,right] = find(table, r, c, 1);
            vvi res;
            for(int i=up; i<=down; i++){
                vector<int> tmp;
                for(int j=left; j<=right; j++){
                    tmp.push_back(table[i][j]);
                }
                res.push_back(tmp);
            }
            tlist.push_back(res);
        }
    }
    for(int i=0; i<tlist.size(); i++){
        int count = 0;
        for(int r=0; r<tlist[i].size(); r++){
            for(int c=0; c<tlist[i][r].size(); c++){
                if(tlist[i][r][c] == 0) count++;
            }
        }
        use.push_back(count);
    }
    for(int i=0; i<blist.size(); i++){
        vvi now = blist[i];
        int nR = now.size();
        int nC = now[0].size();
        int flag2 = 0;
        for(int j=0; j<tlist.size(); j++){
            if(use[j] == 0) continue;
            vvi match = tlist[j];
            for(int d=0; d<4; d++){
                int flag = 0;
                int mR = match.size();
                int mC = match[0].size();
                if(nR == mR && nC == mC){
                    for(int r=0; r<nR; r++){
                        for(int c=0; c<nC; c++){
                            if(now[r][c] != match[r][c]){
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 1)   break;
                    }
                    if(flag == 0){
                        answer += use[j];
                        use[j] = 0;
                        flag2 = 1;
                        break;
                    }
                }
                match = spin(match);
            }
            if(flag2 == 1)  break;
        }
    }
    return answer;
}