#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[100001];
int INF = 0x3f3f3f3f;

int main(){
   int n, k;
   cin>>n>>k;
   memset(dp, INF, sizeof(dp));
   int cnt = 0;
   int fast = INF;
   queue<pair<int, int>> q;
   dp[n] = 0;
   q.push({n,0});
   while(!q.empty()){
      int now = q.front().first;
      int time = q.front().second;
      q.pop();
      if(time>fast)   continue;
      if(now==k){
         if(fast==INF)   fast = time;
         if(time==fast){
            cnt++;
         }
         continue;
      }
      if(now*2<=k+1&&dp[now*2]>=time+1&&now!=0){
         q.push({now*2, time+1});
         dp[now*2] = time+1;
      }
      if(now-1>=0&&dp[now-1]>=time+1){
         dp[now-1] = time+1;
         q.push({now-1, time+1});
      }
      if(now+1<=k&&dp[now+1]>=time+1){
         dp[now+1] = time+1;
         q.push({now+1, time+1});
      }
   }
   cout<<fast<<'\n'<<cnt<<'\n';
   return 0;
}
