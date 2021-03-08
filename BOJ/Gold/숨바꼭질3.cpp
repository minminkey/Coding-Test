#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[100001];
int INF = 0x3f3f3f3f;

struct cmp {
   bool operator()(pair<int, int>&a, pair<int, int>&b) {
      if (a.second == b.second) {
         return a.first > b.first;
      }
      else {
         return a.second > b.second;
      }
   }
};

int main(){
   int n, k;
   cin>>n>>k;
   memset(dp, INF, sizeof(dp));
   dp[n] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
   q.push({n,0});
   while(!q.empty()){
      int now = q.top().first;
      int time = q.top().second;
      // cout<<now<<' '<<time<<endl;
      q.pop();
      int flag = 0;
      for(int i=now; i<=k+1; i = i*2){
         if(i==0) break;
         if(i==k){
            flag = 1;
            break;
         }
         if(dp[i]>time){
            dp[i] = time;
            q.push({i, time});
         }
      }
      if(flag==1){
         cout<<time<<endl;
         break;
      }
      if(now+1==k||now-1==k){
         cout<<time+1<<endl;
         break;
      }
      if(now-1>=0&&dp[now-1]>time+1){
         dp[now-1] = time + 1;
         q.push({now-1, time+1});
      }
      if(now+1<=100000&&dp[now+1]>time+1){
         dp[now+1] = time + 1;
         q.push({now+1, time+1});
      }
   }
}
