#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<int> times;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   string tmp;
   cin>>n>>tmp;
   int total = stoi(tmp.substr(0,2))*3600 + stoi(tmp.substr(3,2))*60 + stoi(tmp.substr(6,2));
   for(int i=0; i<n; i++){
       string t;
       cin>>t;
       int input = stoi(t.substr(0,2))*60 + stoi(t.substr(3,2));
       times.push_back(input);
   }
   // cout<<total<<endl;
   // for(int i=0; i<n; i++){
   //     cout<<times[i]<<endl;
   // }
   queue<int> q;
   int sum = 0;
   int idx = 0;
   int preidx = 1;
   while(sum<total){
      sum += times[idx];
      q.push(times[idx]);
      idx++;
   }
   int ansNum = q.size();
   int ansIdx = 1;
   for(int i=idx; i<n; i++){
      while(sum>=total){
         sum -= q.front();
         q.pop();
         preidx++;
      }
      sum += times[i];
      q.push(times[i]);
      if(q.size()>ansNum){
         ansNum = q.size();
         ansIdx = preidx;
      }
   }
   cout<<ansNum<<' '<<ansIdx<<'\n';
   
   return 0;
}