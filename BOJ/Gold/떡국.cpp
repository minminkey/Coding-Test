#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bowl;

bool fool(int limit){
   int now[500001]={0,};
   for(int i=0; i<limit; i++){
      now[i] = 0x3f3f3f3f;
   }
   int idx = 0;
   for(int i=0; i<bowl.size(); i++){
      if(now[idx]<=bowl[i])   return false;
      now[idx] = bowl[i];
      idx = (idx+1)%limit;
   }
   return true;
}

int main()
{
   int n;
   cin>>n;
   for(int i=0; i<n; i++){
      int tmp;
      cin>>tmp;
      bowl.push_back(tmp);
   }
   sort(bowl.begin(), bowl.end(), greater<int>());
   int s=1;
   int e=n;
   int ans = 0;
   while(s<=e){
      int mid = (s+e)/2;
      if(fool(mid)){
         e = mid-1;
         ans = mid;
      }
      else{
         s = mid+1;
      }
   }
   cout<<ans<<endl;
   return 0;
}