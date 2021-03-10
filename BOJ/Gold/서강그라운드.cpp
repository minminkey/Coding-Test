#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int item[110];
int edge[110][110];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   memset(edge, 0x3f3f3f3f, sizeof(edge));
   int n, m, r;
   cin>>n>>m>>r;
   for(int i=1; i<=n; i++){
      int num;
      cin>>num;
      item[i] = num;
   }
   for(int i=0; i<r; i++){
      int s, e, t;
      cin>>s>>e>>t;
      edge[s][e] = t;
      edge[e][s] = t;
   }
   for(int k=1; k<=n; k++){
      for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
            if(i==j) continue;
            edge[i][j] = min(edge[i][k] + edge[k][j], edge[i][j]);
         }
      }
   }
   int ans = 0;
   for(int i=1; i<=n; i++){
      int sum=item[i];
      for(int j=1; j<=n; j++){
         if(i==j) continue;
         if(edge[i][j]<=m){
            sum += item[j];
         }
      }
      ans = max(ans, sum);
   }
   cout<<ans<<'\n';
   return 0;
}
