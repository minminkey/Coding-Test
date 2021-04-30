#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

string mp[10001];
int visit[10001][501];
int R, C;
int ans = 0;
int dr[3] = {-1, 0, 1};
int dc[4] = {1, 1, 1};

bool dfs(int r, int c){
    visit[r][c] = 1;
    if(c==C-1){
        // ans++;
        return true;
    }
    for(int i=0; i<3; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<0||nc<0||nr>=R||nc>=C||visit[nr][nc]==1||mp[nr][nc]=='x')    continue;
        // cout<<nr<<' '<<nc<<'\n';
        bool flag = dfs(nr, nc);
        if(flag)    return flag;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    for(int i=0; i<R; i++){
        cin>>mp[i];
    }
    for(int i=0; i<R; i++){
        ans += dfs(i,0);
    }
    cout<<ans<<'\n';
    return 0;
}
