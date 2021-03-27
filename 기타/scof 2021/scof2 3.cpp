#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string.h>
using namespace std;

vector<int> child[500001];
vector<int> real[500001];
int visit[500001];
int post[500001];

vector<int> findAll(int idx){
   int s = child[idx].size();
   for(int i=0; i<s; i++){
      // cout<<child[idx][i]<<endl;
      // if(visit[child[idx][i]]==1)   continue;
      // visit[child[idx][i]] = 1;
      vector<int> tmp = findAll(child[idx][i]);
      // cout<<idx<<' '<<child[idx][i]<<endl;
      child[idx].insert(child[idx].end(), tmp.begin(), tmp.end());
   }
   return child[idx];
}
   set<int> ans[500001];


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, Q;
   cin>>n>>Q;
   for(int i=0; i<n-1; i++){
      int p, c;
      cin>>p>>c;
      child[p].push_back(c);
      post[c]++;
   }
   int pack;
   for(int i=1; i<=n; i++){
      if(post[i]==0){
         pack = i;
         break;
      }
   }
   child[pack] = findAll(pack);
   for(int j=1; j<=n; j++){
      for(int i=0; i<child[j].size(); i++){
         ans[j].insert(child[j][i]);
      }
   }
   for(int i=0; i<Q; i++){
      int p, c;
      cin>>p>>c;
      auto it = ans[p].find(c);
      if(it==ans[p].end()){
         cout<<"no"<<'\n';
      }
      else     cout<<"yes"<<'\n';
   }
   return 0;
}