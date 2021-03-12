#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[1001];
int build[1001] = {0,};

int findTime(int now, vector<int> order[1001]){
   if(dp[now]!=-1) return dp[now];
   int maxTime = 0;
   for(int i=0; i<order[now].size(); i++){
      int next = order[now][i];
      if(dp[next]==-1){
         dp[next] = findTime(next, order);
      }
      maxTime = max(maxTime, dp[next]);
   }
   return maxTime + build[now];
} 

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int T;
   vector<int> ans;
   cin>>T;
   while(T--){
      memset(dp, -1, sizeof(dp));
      memset(build, 0, sizeof(build));
      int n, k, target;
      vector<int> order[1001];
      cin>>n>>k;
      for(int i=1; i<=n; i++){
         int t;
         cin>>build[i];
      }
      for(int i=0; i<k; i++){
         int a, b;
         cin>>a>>b;
         order[b].push_back(a);
      }
      cin>>target;
      dp[target] = findTime(target, order);
      ans.push_back(dp[target]);
   }
   for(int i=0; i<ans.size(); i++){
      cout<<ans[i]<<'\n';
   }
   return 0;
}
