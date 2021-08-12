#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

vector<pair<int, int>> edge[1001];

int trace[1001];
int dist[1001];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, m;
   cin>>n>>m;
   for(int i=0; i<=n; i++){
	   dist[i] = 0x3f3f3f3f;
   }
   for(int i=0; i<m;i++){
      int s, e, d;
      cin>>s>>e>>d;
      edge[s].push_back({e,d});
   }
   int s, e;
   cin>>s>>e;
   dist[s] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
   pq.push({0, s});
   while(!pq.empty()){
	   int cost = pq.top().first;
	   int now = pq.top().second;
	   pq.pop();
	   if(dist[now]<cost)	continue;
	   for(int i=0; i<edge[now].size(); i++){
		   int next = edge[now][i].first;
		   int ncost = edge[now][i].second + cost;
		   if(ncost<dist[next]){
			   dist[next] = ncost;
			   trace[next] = now;
			   pq.push({ncost, next});
		   }
	   }
   }
   cout<<dist[e]<<endl;
   vector<int> ans;
   int now = e;
   while(now){
	   ans.push_back(now);
	   now = trace[now];
   }
   cout<<ans.size()<<endl;
   for(int i=ans.size()-1; i>=0; i--){
	   cout<<ans[i]<<' ';
   }
   cout<<endl;
   return 0;
}
