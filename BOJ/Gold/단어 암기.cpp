#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> alpha[30000];
int ck[30000];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, m;
   cin>>n>>m;
   for(int i=0; i<n; i++){
      string s;
      cin>>s;
      int visit[30000] = {0, };
      for(int j=0; j<s.length(); j++){
         if(visit[s[j]-'a']==0){
            visit[s[j]-'a'] = 1;
            alpha[s[j]-'a'].push_back(i);
         }
      }
   }
   vector<int> answer;
   int ans = n;
   for(int i=0; i<m; i++){
      int t;
      char c;
      cin>>t>>c;
      int idx = c - 'a';
      if(t==1){
         for(int j=0; j<alpha[idx].size(); j++){
            if(ck[alpha[idx][j]]==0)   ans--;
            ck[alpha[idx][j]]++;
         }
      }
      else{
         for(int j=0; j<alpha[idx].size(); j++){
            if(ck[alpha[idx][j]]>0){
               ck[alpha[idx][j]]--;
               if(ck[alpha[idx][j]]==0) ans++;
            }
         }
      }
      answer.push_back(ans);
   }
   for(int i=0; i<answer.size(); i++){
      cout<<answer[i]<<'\n';
   }
   return 0;
}
