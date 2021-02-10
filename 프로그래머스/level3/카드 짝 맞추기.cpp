#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int minSum = 0x3f3f3f3f;
vector<int> num;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void go(vector<vector<int>> board, int d, int &r, int &c){
    int nextR = r + dr[d];
    int nextC = c + dc[d];
    while(nextR>=0&&nextC>=0&&nextR<4&&nextC<4){
        r = nextR;
        c = nextC;
        if(board[r][c]!=0)  return;
        nextR = r + dr[d];
        nextC = c + dc[d];
    }
}
struct Info{
    int r;
    int c;
    int cnt;
};
int findCard(vector<vector<int>> &board, int target, int &r, int &c){
    if(board[r][c]==target){
        board[r][c]=0;
        return 0;
    }
    vector<vector<int>> visit(4, vector<int>(4));
    queue<struct Info> q;
    struct Info f = {r,c,0};
    q.push(f);
    while(!q.empty()){
        struct Info now = q.front();
        q.pop();
        int nr, nc;
        for(int i=0; i<4; i++){
            int nr = now.r;
            int nc = now.c;
            go(board, i, nr, nc);
            if(nr<0||nc<0||nr>=4||nc>=4||visit[nr][nc]==1)    continue;
            if(board[nr][nc]==target){
                board[nr][nc]=0;
                r = nr;
                c = nc;
                return now.cnt + 1;
            }
            struct Info next = {nr, nc, now.cnt+1};
            visit[nr][nc] = 0;
            q.push(next);
        }
        for(int i=0; i<4; i++){
            nr = now.r + dr[i];
            nc = now.c + dc[i];
            if(nr<0||nc<0||nr>=4||nc>=4||visit[nr][nc]==1)    continue;
            if(board[nr][nc]==target){
                // cout<<"find : "<<nr<<' '<<nc<<' '<<board[nr][nc]<<endl;
                board[nr][nc]=0;
                r = nr;
                c = nc;
                return now.cnt + 1;
            }
            struct Info next = {nr, nc, now.cnt+1};
            visit[nr][nc] = 0;
            q.push(next);
        }
    }
    return -1;
}
void findAll(vector<vector<int>> board, vector<int> num, int r, int c, int cnt, int sum){
    if(cnt==num.size()){
        if(sum<minSum)  minSum = sum;
        return;
    }
    for(int i=0; i<num.size(); i++){
        vector<vector<int>> tboard = board;
        if(num[i]==0)   continue;
        int tn = num[i];
        num[i] = 0;
        int tr = r;
        int tc = c;
        int tsum = sum;
        tsum += findCard(tboard, tn, tr, tc);
        tsum += findCard(tboard, tn, tr, tc);
        findAll(tboard, num, tr, tc, cnt+1, tsum);
        num[i] = tn;
    }
}
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    int n[7] = {0, };
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(board[i][j]!=0)  n[board[i][j]]++;
        }
    }
    for(int i=1; i<=6; i++){
        if(n[i]!=0) num.push_back(i);
    }
    findAll(board, num, r, c, 0, 0);
    answer = minSum + num.size()*2;
    return answer;
}