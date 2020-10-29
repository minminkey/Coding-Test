
#include <bits/stdc++.h>
using namespace std;

int N;
int ans = 0;
int board[20][20];
int dr[3] = {0, 1, 1};
int dc[3] = {1, 1, 0};
bool ck(int nr, int nc, int i){
    if(i==0){
        if(board[nr][nc]==1||(nc==N&&nr!=N)) return true;
    }
    else if(i==1){
        if(board[nr][nc]==1||board[nr-1][nc]==1||board[nr][nc-1]==1)    return true;
    }
    else{
        if(board[nr][nc]==1||(nr==N&&nc!=N)) return true;
    }
    return false;
}
void Bfs(int R, int C, int D){
    int r = R + dr[D];
    int c = C + dc[D];
    if(r==N&&c==N){
        ans++;
        return;
    }
    for(int i=0; i<3; i++){
        if(D==0&&i==2)  continue;
        if(D==2&&i==0)  continue;
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<1||nc<1||nr>N||nc>N)  continue;
        if(ck(nr, nc, i))   continue;
        Bfs(r,c,i);
    }
    return;
}
int main(){
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>board[i][j];
        }
    }
    Bfs(1,1,0);
    cout<<ans<<'\n';
}
