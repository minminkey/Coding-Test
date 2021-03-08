#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int INF = 0x3f3f3f3f;
int dp[101][101];

int main(){
   memset(dp, INF, sizeof(dp));
   int n, m;
   cin>>n>>m;
   for(int i=0; i<m; i++){
      int s, e, d;
      cin>>s>>e>>d;
      if(dp[s][e]>d) dp[s][e] = d;
   }
   for(int k=1; k<=n; k++){
      for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
            if(i==j) continue;
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
         }
      }
   }
   for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
         if(dp[i][j]==INF){
            dp[i][j] = 0;
         }
         cout<<dp[i][j]<<' ';
      }
      cout<<endl;
   }
   return 0;
}
