#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <string.h>
using namespace std;

int R, C;
char mp[21][21];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int ans = 0;

void dfs(int r, int c, int cnt, int visit[]){
    ans = max(ans, cnt);
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<0||nc<0|| nr>=R||nc>=C)   continue;
        if(visit[mp[nr][nc]-'A']==1)    continue;
        visit[mp[nr][nc]-'A'] = 1;
        dfs(nr, nc, cnt+1, visit);
        visit[mp[nr][nc]-'A'] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>R>>C;
    for(int i=0; i<R; i++){
        string tmp;
        cin>>tmp;
        for(int j=0; j<tmp.length(); j++){
            mp[i][j] = tmp[j];
        }
    }
    int visit[27] = {0, };
    visit[mp[0][0]-'A'] = 1;
    dfs(0, 0, 1, visit);
    cout<<ans<<'\n';
    return 0;
}
