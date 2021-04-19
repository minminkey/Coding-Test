#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <tuple>
#include <string.h>
using namespace std;

long long n,c;
vector<long long> Right;
vector<long long> Left;
vector<int> r, l;

void dfs(int idx, long long cnt, int flag){
   if(flag==0){
      if(idx==l.size()){
         Left.push_back(cnt);
         return;
      }
      dfs(idx+1, cnt+l[idx], flag);
   }
   else{
      if(idx==r.size()){
         Right.push_back(cnt);
         return;
      }
      dfs(idx+1, cnt+r[idx], flag);
   }
   dfs(idx+1, cnt, flag);
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>c;
   for(int i=0; i<n; i++){
      int k;
      cin>>k;
      if(i>n/2)   r.push_back(k);
      else        l.push_back(k);
   }
   dfs(0,0,0);
   dfs(0,0,1);
   sort(Left.begin(), Left.end());
   sort(Right.begin(), Right.end());
   long long ans = 0;
   for(int i=0; i<Left.size(); i++){
      auto iter = upper_bound(Right.begin(), Right.end(), c-Left[i]);
      if(iter!=Right.begin()){
         ans += iter - Right.begin();
      }
   }
   cout<<ans<<'\n';
   return 0;
}