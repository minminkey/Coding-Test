#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int mp[501][501];
int dp[501][501];

int cnt = 0;

int ck(int r, int c){
    if(dp[r][c]!=-1) return dp[r][c];
    int now = mp[r][c];
    int Max = 1;
    for(int i=0; i<4; i++){
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr<0||nc<0||nr>=N||nc>=N)    continue;
        if(now>=mp[nr][nc])             continue;
        if(dp[nr][nc]!=-1)   Max = max(Max, 1+dp[nr][nc]);
        else                Max = max(Max, 1+ck(nr, nc));
    }
    return dp[r][c] = Max;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>mp[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans = max(ans, ck(i, j));
        }
    }
    cout<<ans<<'\n';
	return 0;
}