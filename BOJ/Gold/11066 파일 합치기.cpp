#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int dp[501][501];
int arr[501];
int sum[501];

int go(int s, int e){
   if(dp[s][e] != 0x3f3f3f3f) return dp[s][e];
   if(s==e) return dp[s][e] = 0;
   if(s+1==e)  return dp[s][e] = arr[s]+arr[e];
   for(int i=s; i<e; i++){
      dp[s][e] = min(dp[s][e], go(s,i)+go(i+1, e));
   }
   return dp[s][e] += sum[e] - sum[s-1];
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
      memset(dp, 0x3f3f3f3f, sizeof(dp));
      memset(arr, 0, sizeof(arr));
      int K;
      cin>>K;
      for(int i=1; i<=K; i++){
         cin>>arr[i];
         sum[i] = sum[i-1] + arr[i];
      }
      cout<<go(1, K)<<'\n';
   }
   return 0;
}