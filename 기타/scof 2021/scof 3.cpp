#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int mp[55][55];
int dp[55][55];
int col[55][55];
int type[55];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   int ans = 0;
   cin>>n;
   for(int i=0; i<n; i++){
       string s;
       cin>>s;
       for(int j=0; j<s.length(); j++){
           mp[i][j] = s[j] - '0';
           if(mp[i][j]==1){
               dp[i][j] = 1;
           }
       }
   }
   for(int i=1; i<n; i++){
       for(int j=1; j<n; j++){
           if(mp[i][j]==0)  continue;
           dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
       }
   }
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           cout<<dp[i][j]<<' ';
       }
       cout<<endl;
   }
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           int now = dp[i][j];
           for(int k=1; k<=now; k++){
               type[k]++;
               ans++;
           }
       }
   }
   cout<<"total: "<<ans<<'\n';
   for(int i=1; i<=50; i++){
       if(type[i]==0)   break;
       cout<<"size["<<i<<"]: "<<type[i]<<'\n';
   }
   return 0;
}