#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> node[100001];
int parent[100001];

int main(){
   ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n;
   cin>>n;
   for(int i=0; i<n-1; i++){
      int a, b;
      cin>>a>>b;
      node[a].push_back(b);
      node[b].push_back(a);
   }
   queue<int> q;
   q.push(1);
   parent[1] = -1;
   while(!q.empty()){
      int now = q.front();
      q.pop();
      // cout<<now<<endl;
      for(int i=0; i<node[now].size(); i++){
         if(parent[node[now][i]]!=0)   continue;
         parent[node[now][i]] = now;
         q.push(node[now][i]);
      }
   }

   for(int i=2; i<=n; i++){
      cout<<parent[i]<<'\n';
   }
   return 0;
}