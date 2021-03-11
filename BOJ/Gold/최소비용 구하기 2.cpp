#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct Node{
   int city;
   int dist;
   vector<int> pre;
};
vector<pair<int, int>> edge[1001];
struct Node node[1001];
struct cmp{
   bool operator()(Node &a, Node &b){
      if(a.dist==b.dist){
         return a.city > b.city;
      }
      return a.dist > b.dist;
   }
};

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, m;
   cin>>n>>m;
   for(int i=0; i<m;i++){
      int s, e, d;
      cin>>s>>e>>d;
      edge[s].push_back({e,d});
   }
   int s, e;
   cin>>s>>e;
   for(int i=1; i<=n; i++){
      node[i].dist = 0x3f3f3f3f;
   }
   node[s].dist = 0;
   priority_queue<Node, vector<Node>, cmp> pq;
   vector<int> init;
   init.push_back(s);
   struct Node start = {s, 0, init};
   struct Node ans;
   pq.push(start);
   while(!pq.empty()){
      int now = pq.top().city;
      int dist = pq.top().dist;
      vector<int> pre = pq.top().pre;
      pq.pop();
      for(int i=0; i<edge[now].size(); i++){
         int next = edge[now][i].first;
         int nextd = edge[now][i].second;
         pre.push_back(next);
         struct Node nextNode = {next, dist+nextd, pre};
         if(node[next].dist>nextNode.dist){
            pq.push(nextNode);
            node[next] = nextNode;
         }
         pre.pop_back();
      }
   }
   cout<<node[e].dist<<'\n'<<node[e].pre.size()<<'\n';
   for(int i=0; i<node[e].pre.size(); i++){
      cout<<node[e].pre[i]<<' ';
   }
   cout<<'\n';
   return 0;
}
