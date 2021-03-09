#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int main(){
   ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   long long a, b;
   cin>>a>>b;
   queue<pair<long long, long long>> q;
   q.push({a,0});
   long long ans = -1;
   while(!q.empty()){
      long long now = q.front().first;
      long long cnt = q.front().second;
      q.pop();
      if(now==b){
         ans = cnt;
         break;
      }
      if(now*2<=b){
         q.push({now*2,cnt+1});
      }
      if(now*10+1<=b){
         q.push({now*10+1,cnt+1});
      }
   }
   if(ans == -1)  cout<<-1<<'\n';
   else           cout<<ans+1<<'\n';
   return 0;
}