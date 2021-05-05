#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define xx first
#define yy second
const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int n, m, board[21][21];
bool vst[21][21], chk[21][21];


//색깔이 color인 {그룹의 크기, 무지개 개수}를 리턴한다.
//flag==1이면, board[x][y]를 -2로 바꾼다.
pii dfs(int color, int x, int y, bool flag){
    if(vst[x][y]) return {0,0};
    vst[x][y] = 1;
    if(board[x][y] > 0) chk[x][y] = 1;

    pii size = {1, 0};
    size.yy += (board[x][y] == 0);
    for(int d=0; d<4; ++d){
        int nx = x+dir[d][0], ny = y+dir[d][1];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(board[nx][ny] == 0 || board[nx][ny] == color){
            pii ret = dfs(color, nx, ny, flag);
            size.xx += ret.xx;
            size.yy += ret.yy;
        }
    }
    if(flag) board[x][y] = -2;
    return size;
}

void gravity(){
    for(int y=0; y<n; ++y){
        for(int sx=n-1; sx>=0; --sx){
            //(sx, y)를 떨어뜨린다
            if(board[sx][y] == -1) continue;
            for(int x=sx+1; x<n; ++x){
                if(board[x][y] == -1) break;
                if(board[x][y] == -2) swap(board[x-1][y], board[x][y]);
                else break;
            }
        }
    }
}

int tmp[21][21];
void rotate(){
    //임시 배열 tmp를 활용하여 배열을 회전
    //(x1, y1) : tmp를 정방향으로 순회
    //(x2, y2) : board를 회전된 방향으로 순회
    for(int x1=0, y2=n-1; x1<n; ++x1, --y2)
        for(int y1=0, x2=0; y1<n; ++y1, ++x2)
            tmp[x1][y1] = board[x2][y2];
    memcpy(board, tmp, sizeof(board));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> board[i][j];

    int ans = 0;
    while(1){
        //조건을 만족하는 그룹을 구한다
        //chk[x][y] : 이번 while에서 (x,y)를 한번이라도 방문 했는가?
        pair<pii, pii> maxret = {{-1, -1}, {-1, -1}}; //{{블록 크기, 무지개 개수}, 대표 블록}
        memset(chk, 0, sizeof(chk));
        for(int x=0; x<n; ++x){
            for(int y=0; y<n; ++y){
                if(board[x][y] <= 0 || chk[x][y]) continue;
                //vst[x][y] : 이번 dfs에서 (x,y)를 방문 했는가?
                memset(vst, 0, sizeof(vst));
                pair<pii, pii> ret = {dfs(board[x][y], x, y, 0), {x,y}};
                maxret = max(maxret, ret);
            }
        }

        if(maxret.xx.xx < 2) break; //더 이상 그룹이 없다.

        //그룹을 제거한다
        auto [size, center] = maxret;
        memset(vst, 0, sizeof(vst));
        assert(size == dfs(board[center.xx][center.yy], center.xx, center.yy, 1));
        ans += size.xx*size.xx;

        //중력 -> 회전 -> 중력
        gravity();
        rotate();
        gravity();
    }

    cout << ans;   
}