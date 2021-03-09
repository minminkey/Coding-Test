#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int down[100001][3];
int dp[3];
// int dpmin[100001][3];

int main(){
   ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n;
   cin>>n;
   for(int i=0; i<n; i++){
      for(int j=0; j<3; j++){
         int tmp;
         cin>>tmp;
         down[i][j] = tmp;
      }
   }
   for(int i=0; i<3; i++){
      dp[i] = down[0][i];
   }
   for(int i=1; i<n; i++){
      int a = down[i][0] + max(dp[0], dp[1]);
      int b = down[i][1] + max(dp[0], max(dp[1], dp[2]));
      int c = down[i][2] + max(dp[1], dp[2]);
      dp[0] = a;
      dp[1] = b;
      dp[2] = c;
   }
   int big = max(dp[0], max(dp[1], dp[2]));
   memset(dp, 0, sizeof(dp));
   for(int i=0; i<3; i++){
      dp[i] = down[0][i];
   }
   for(int i=1; i<n; i++){
      int a = down[i][0] + min(dp[0], dp[1]);
      int b = down[i][1] + min(dp[0], min(dp[1], dp[2]));
      int c = down[i][2] + min(dp[1], dp[2]);
      dp[0] = a;
      dp[1] = b;
      dp[2] = c;
   }
   int small = min(dp[0], min(dp[1], dp[2]));
   cout<<big<<' '<<small<<'\n';
   return 0;
}