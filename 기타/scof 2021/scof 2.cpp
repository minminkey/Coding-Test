#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int dp[55];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   string road;
   cin>>road;
   dp[0] = 1;
   if(road[1]=='1') dp[1] = 1;
   for(int i=2; i<road.length(); i++){
       if(road[i]=='0')   continue;
       dp[i] = dp[i-1] + dp[i-2];
   }
   cout<<dp[n-1]<<'\n';
   return 0;
}