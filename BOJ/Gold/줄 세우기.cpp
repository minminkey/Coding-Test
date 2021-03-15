#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<int> pre[32010];
int post[32010];
int visit[32010];

int main(){
   ios_base::sync_with_stdio(0);
   vector<int> ans;
   cin.tie(0);
   int n, m;
   cin>>n>>m;
   for(int i=0; i<m; i++){
      int a, b;
      cin>>a>>b;
      pre[a].push_back(b);
      post[b]++;
   }
   queue<int> q;
   for(int i=1; i<=n; i++){
      if(post[i]==0){
         q.push(i);
      }
   }
   for(int i=1; i<=n; i++){
      int now = q.front();
      q.pop();
      ans.push_back(now);
      for(int j=0; j<pre[now].size(); j++){
         int next = pre[now][j];
         post[next]--;
         if(post[next]==0){
            q.push(next);
         }
      }
   }
   for(int i=0; i<ans.size(); i++){
      cout<<ans[i]<<' ';
   }
   cout<<"\n";
}