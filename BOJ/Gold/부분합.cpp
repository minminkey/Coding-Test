#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int num[100001];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, s;
   cin>>n>>s;
   for(int i=0; i<n; i++){
      cin>>num[i];
   }
   queue<int> q;
   long long sum = 0;
   int l = 0x3f3f3f3f;
   for(int i=0; i<n; i++){
      q.push(num[i]);
      sum += num[i];
      if(sum>=s){
         while(!q.empty()){
            if(sum-q.front()>=s){
               sum -= q.front();
               q.pop();
            }
            else{
               break;
            }
         }
         if(q.size()<l){
            l = q.size();
         }
      }
   }
   if(l==0x3f3f3f3f){
      cout<<0<<'\n';
   }
   else   cout<<l<<'\n';
   return 0;
}
