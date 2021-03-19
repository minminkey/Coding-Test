#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<int> num[2];

int dp[1001][1001];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   for(int i=0; i<2; i++){
      string s;
      cin>>s;
      for(int j=0; j<s.length(); j++){
         num[i].push_back(s[j]-'A');
      }
   }
   for(int i=0; i<num[1].size(); i++){
      for(int j=0; j<num[0].size(); j++){
         if(num[1][i]==num[0][j]){
            dp[i+1][j+1] = dp[i][j]+1;
         }
         else{
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
         }
      }
   }
   int r = num[1].size();
   int c = num[0].size();
   vector<char> ans;
   cout<<dp[r][c]<<'\n';
   while(dp[r][c]!=0){
      if(dp[r][c] == dp[r-1][c]){
         r--;
      }
      else if(dp[r][c] == dp[r][c-1]){
         c--;
      }
      else{
         char t = num[0][c-1]+'A';
         ans.push_back(t);
         r--;
         c--;
      }
   }
   for(int i=ans.size()-1; i>=0; i--){
      cout<<ans[i];
   }
   cout<<'\n';
   return 0;
}