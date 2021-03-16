#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<long long> num;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0; i<n; i++){
      int k;
      cin>>k;
      num.push_back(k);
   }
   long long ans = 4000000001;
   sort(num.begin(), num.end());
   int l, m, r;
   for(int i=0; i<n-2; i++){
      int mi = i+1;
      int pi = n-1;
      while(mi<pi){
         long long int tmp = num[pi]+num[mi]+num[i];
         // cout<<tmp<<endl;
         if(ans > abs(tmp)){
            ans = abs(tmp);
            l = num[i];
            m = num[mi];
            r = num[pi];
         }
         if(tmp<=0){
            mi++;
         }
         else{
            pi--;
         }
      }
   }
   cout<<l<<' '<<m<<' '<<r<<'\n';
   return 0;
}