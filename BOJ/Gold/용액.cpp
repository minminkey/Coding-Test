#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int num[100001];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0; i<n; i++){
      cin>>num[i];
   }
   long long ans = 2000000001;
   int l, r;
   int mi = 0; 
   int pi = n-1;
   while(mi<pi){
      long long tmp = num[pi]+num[mi];
      if(ans > abs(tmp)){
         ans = abs(tmp);
         l = num[mi];
         r = num[pi];
      }
      if(tmp<=0){
         mi++;
      }
      else{
         pi--;
      }
   }
   cout<<l<<' '<<r<<'\n';
   return 0;
}