#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int mp[101][10001];
long long dp[101][10001];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, m;
   cin>>m>>n;
   for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){
           cin>>mp[i][j];
       }
   }
//    dp[1][1] = mp[1][1];
   for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){
           dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + mp[i][j];
           cout<<dp[i][j]<<' ';
       }
       cout<<endl;
   }

   cout<<dp[n][m]<<'\n';
   return 0;
}