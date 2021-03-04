#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int mp[1001][1001];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
struct Node{
   int r, c;
   int d, f;
};
int dp[2][1001][1001];

int main(){
   int n, m;
   cin>>n>>m;
   for(int i=1; i<=n; i++){
      string tmp;
      cin>>tmp;
      for(int j=1; j<=m; j++){
         mp[i][j] = tmp[j-1] - '0';
         dp[0][i][j] = 0x3f3f3f3f;
         dp[1][i][j] = 0x3f3f3f3f;
      }
   }
   struct Node start = {1,1,0,0};
   queue<struct Node> q;
   dp[0][1][1] = 0;
   dp[1][1][1] = 0;
   q.push(start);
   while(!q.empty()){
      struct Node now = q.front(); 
      q.pop();
      for(int i=0; i<4; i++){
         int nr = now.r + dr[i];
         int nc = now.c + dc[i];
         int nd = now.d + 1;
         struct Node next = {nr, nc, nd, now.f};
         if(nr<1||nr>n||nc<1||nc>m) continue;
         if(mp[nr][nc]==1){
            if(now.f==1)   continue;
            if(dp[1][nr][nc]>nd){
               dp[1][nr][nc] = nd;
               next.f = 1;
               q.push(next);
            }
         }
         else{
            if(now.f==0&&dp[0][nr][nc]>nd){
               dp[0][nr][nc] = nd;
               q.push(next);
            }
            else if(now.f==1&&dp[1][nr][nc]>nd){
               dp[1][nr][nc] = nd;
               q.push(next);
            }
         }
      }
   }
   int ans = min(dp[0][n][m], dp[1][n][m]);
   if(ans==0x3f3f3f3f)  cout<<-1<<'\n';
   else                 cout<<ans+1<<'\n';
   return 0;
}
