#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int v, e;
   int a, b, c;
   vector<pair<int, int>> edge[10001];
   cin>>v>>e;
   for(int i=0; i<e; i++){
      cin>>a>>b>>c;
      edge[a].push_back({c,b});
      edge[b].push_back({c,a});
   }
   priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
   int now = 1;
   int visit[10001] = {0,};
   visit[now] = 1;
   int ans = 0;
   for(int i=0; i<v-1; i++){
      for(int j=0; j<edge[now].size(); j++){
         pq.push({edge[now][j].first, edge[now][j].second});
      }
      while(!pq.empty()){
         if(visit[pq.top().second]==0) break;
         pq.pop();
      }
      int next = pq.top().second;
      visit[next] = 1;
      ans += pq.top().first;
      now = next;
      pq.pop();
   }
   cout<<ans<<'\n';
   return 0;
}
