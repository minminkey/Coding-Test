#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<int> idx;
int ck[600001] = {0, };
int edge[600001] = {0, };
// int ans[100001] = {0, };
vector<int> dp;
int pre[600001] = {0, };

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0; i<n; i++){
      int a, b;
      cin>>a>>b;
      idx.push_back(a);
      edge[a] = b;
   }
   sort(idx.begin(), idx.end());
   // for(int i=0; i<n; i++){
   //    cout<<idx[i]<<' '<<edge[idx[i]]<<endl;
   // }
   dp.push_back(0);
   for(int i=0; i<idx.size(); i++){
      int id = idx[i];
      int now = edge[id];
      if(edge[dp.back()]<now){
         pre[id] = dp.back();
         dp.push_back(id);
         continue;
      }
      int s = 1;
      int e = dp.size()-1;
      int t = 0;
      while(s<=e){
         int m = (s+e)/2;
         if(edge[dp[m]]<now){
            s = m+1;
            t = m;
         }
         else{
            e = m-1;
         }
      }
      // cout<<id<<' '<<t<<endl;
      dp[t+1] = id;
      pre[id] = dp[t];
   }
   cout<<n+1-dp.size()<<endl;
   int before = dp.back();
   while(before>0){
      // cout<<before<<endl;
      ck[before] = 1;
      before = pre[before];
   }
   for(int i=0; i<idx.size(); i++){
      if(ck[idx[i]]==1)   continue;
      cout<<idx[i]<<'\n';
   }
   return 0;
}