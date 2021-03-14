#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[1000001];
int before[1000001];

void findAll(int n){
   dp[1] = 0;
   before[1] = 0;
   for(int i=2; i<=n; i++){
      dp[i] = dp[i-1] + 1;
      before[i] = i - 1;
      if(i%3==0){
         int next = i/3;
         if(dp[i] > dp[next]+1){
            dp[i] = dp[next] + 1;
            before[i] = next;
         }
      }
      if(i%2==0){
         int next = i/2;
         if(dp[i] > dp[next]+1){
            dp[i] = dp[next] + 1;
            before[i] = next;
         }
      }
   }
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   findAll(n);
   cout<<dp[n]<<'\n';
   int idx = n;
   while(idx!=0){
      cout<<idx<<' ';
      idx = before[idx];
   }
   cout<<'\n';
   return 0;
}
