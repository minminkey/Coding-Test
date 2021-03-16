#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int team[100001] = {0, };
int part[100001] = {0, };
int visit[100001] = {0,};
int ans = 0;

void dfs(int now, int visit[], vector<int> pre){
   visit[now] = 1;
   int next = part[now];
   if(visit[next] == 0){
      dfs(next, visit, pre);
   }
   else if(team[next]==0){
      for(int i=next; i!=now; i=part[i]){
         ans--;
      }
      ans--;
   }
   team[now] = 1;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
      int n;
      cin>>n;
      ans = n;
      memset(visit, 0, sizeof(visit));
      memset(team, 0, sizeof(team));
      for(int i=1; i<=n; i++){
         cin>>part[i];
      }
      for(int i=1; i<=n; i++){
         if(visit[i]!=0) continue;
         // cout<<i<<endl;
         vector<int> pre;
         dfs(i, visit, pre);
      }
      // for(int i=1; i<=n; i++){
      //    cout<<team[i]<<' ';
      // }
      cout<<ans<<'\n';
   }
   return 0;
}