#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int num[1025][1025];
long long dp[1025][1025];

int main(){
   ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n, m;
   cin>>n>>m;
   for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
         cin>>num[i][j];
         dp[i][j] = num[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
      }
   }
   vector<long long> ans;
   for(int i=0; i<m; i++){
      int x1, x2, y1, y2;
      cin>>x1>>y1>>x2>>y2;
      long long sum = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
      cout<<sum<<'\n';
   }
}