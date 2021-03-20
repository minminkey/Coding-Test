#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<pair<int, int>> times;
bool cmp(pair<int, int> a, pair<int, int> b){
   if(a.second == b.second){
      return a.first<b.first;
   }
   return a.second<b.second;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   cin.ignore();
   for(int i=0; i<n; i++){
      string s;
      getline(cin, s);
      int startTime = 60*stoi(s.substr(0,2))+stoi(s.substr(3,2));
      int endTime = 60*stoi(s.substr(8,2))+stoi(s.substr(11,2));
      times.push_back({startTime, endTime});
   }
   sort(times.begin(), times.end(), cmp);
   queue<int> q;
   int last = times[0].second;
   int start = 0;
   for(int i=0; i<times.size(); i++){
      if(times[i].first>last){
         start = -1;
         break;
      }
      else{
         start = max(start, times[i].first);
      }
   }
   if(start == -1){
      cout<<-1<<'\n';
   }
   else{
      cout<<start<<' '<<last<<endl;
      string k[4];
      k[0] = to_string(start/60);
      k[1] = to_string(start%60);
      k[2] = to_string(last/60);
      k[3] = to_string(last%60);
      for(int i=0; i<4; i++){
         if(k[i].length()==1){
            k[i] = '0' + k[i];
         }
      }
      cout<<k[0]<<':'<<k[1]<<" ~ "<<k[2]<<':'<<k[3]<<'\n';
   }
   return 0;
}