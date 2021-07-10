#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

// 4 5
// 50 45 37 32 30
// 35 50 40 20 25
// 30 30 25 17 28
// 27 24 22 15 10
vector<vector<int>> board;
int n, m;
int dp[501][501];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(int r, int c){
   if(r==m-1&&c==n-1)   return 1;
   if(dp[r][c]!=-1)     return dp[r][c];
   int now = board[r][c];
   dp[r][c] = 0;
   for(int d=0; d<4; d++){
      int nr = r+dr[d];
      int nc = c+dc[d];
      if(nr<0||nr>=m||nc<0||nc>=n)  continue;
      int next = board[nr][nc];
      if(now<=next)                 continue;
      dp[r][c] += dfs(nr, nc);
   }
   return dp[r][c];
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int ans = 0;
   cin>>m>>n;
   for(int i=0; i<m; i++){
      vector<int> tmp;
      for(int j=0; j<n; j++){
         int tp;
         cin>>tp;
         tmp.push_back(tp);
         dp[i][j] = -1;
      }
      board.push_back(tmp);
   }
   ans = dfs(0,0);
   cout<<ans<<'\n';
   return 0;
}