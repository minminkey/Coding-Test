#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int edge[5001][5001];
int INF = 0x3f3f3f3f;
vector<int> node[5001];


int main(){
   int N, Q;
   vector<pair<int, int>> question;
   cin>>N>>Q;
   for(int i=0; i<=N; i++){
      for(int j=0; j<=N; j++){
         edge[i][j] = INF;
      }
   }
   for(int i=0; i<N-1; i++){
      int p,q,r;
      cin>>p>>q>>r;
      edge[p][q] = r;
      edge[q][p] = r;
      node[p].push_back(q);
      node[q].push_back(p);
   }
   vector<int> answer;
   for(int i=0; i<Q; i++){
      int k, v;
      int ans = 0;
      cin>>k>>v;
      int visit[5001] = {0, };
      queue<int> q;
      visit[v] = 1;
      q.push(v);
      while(!q.empty()){
         int now = q.front();
         q.pop();
         for(int j=0; j<node[now].size(); j++){
            int next = node[now][j];
            if(visit[next]==1||edge[now][next]<k)   continue;
            visit[next] = 1;
            ans++;
            q.push(next);
         }
      }
      answer.push_back(ans);
      cout<<ans<<'\n';
   }
   return 0;
}