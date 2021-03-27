#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

vector<pair<int, int>> edge[10001];
int visit[10001];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long answer = 0;
   int n;
   cin>>n;
   int num = 0;
   map<string, int> city;
   for(int i=0; i<n; i++){
      string s, e;
      int dist;
      int st, en;
      cin>>s>>e>>dist;
      auto it = city.find(s);
      if(it==city.end()){
         city.insert({s,num});
         st = num++;
      }
      else{
         st = it->second;
      }
      it = city.find(e);
      if(it==city.end()){
         city.insert({e,num});
         en = num++;
      }
      else{
         en = it->second;
      }
      edge[st].push_back({dist, en});
      edge[en].push_back({dist, st});
   }
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   for(int i=0; i<edge[0].size(); i++){
      pq.push(edge[0][i]);
   }
   visit[0] = 1;
   int now = 1;
   // long long answer = 0;
   // cout<<num<<endl;
   while(!pq.empty()&&now<num){
      int next = pq.top().second;
      int cost = pq.top().first;
      pq.pop();
      if(visit[next]==1)   continue;
      now++;
      visit[next] = 1;
      answer += cost;
      for(int i=0; i<edge[next].size(); i++){
         pq.push(edge[next][i]);
      }
   }
   cout<<answer<<'\n';
   // cout<<pq.top().first<<endl;
   return 0;
}