#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<pair<int, int>> edge[1001];
int N, P, K;
int dp[1001];

struct cmp{
   bool operator()(pair<int, int>&a, pair<int, int>&b){
      return a.first > b.first;
   }
};


bool dijks(int mid){
   priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
   for(int i=0; i<=N; i++){
      dp[i] = 987654321;
   }
   pq.push({0, 1});
   dp[1] = 0;
   while(!pq.empty()){
      auto [cnt, now] = pq.top();
      pq.pop();
      if(dp[now] < cnt) continue;
      for(int i=0; i<edge[now].size(); i++){
         auto [next, cost] = edge[now][i];
         int ncnt = cnt;
         if(cost>mid)   ncnt++;
         if(ncnt<dp[next]){
            dp[next] = ncnt;
            pq.push({ncnt, next});
         }
      }
   }
   return dp[N] <= K;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>N>>P>>K;
   int l = 0;
   int r = 0;
   int ans = -1;
   for(int i=0; i<P; i++){
      int s, e, v;
      cin>>s>>e>>v;
      edge[s].push_back({e,v});
      edge[e].push_back({s,v});
      r = max(r, v);
   }
   while(l<=r){
      int mid = l+ (r-l)/2;
      if(dijks(mid)){
         ans = mid;
         r = mid-1;
      }
      else{
         l = mid+1;
      }
   }
   cout<<ans<<'\n';
   return 0;
}