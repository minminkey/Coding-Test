#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   string origin, boom;
   cin>>origin>>boom;
   vector<char> ans(1000001, ' ');
   int idx = 0;
   for(int i=0; i<origin.length(); i++){
      ans[idx++] = origin[i];
      if(ans[idx-1]==boom[boom.length()-1]){
         if(idx-boom.length()<0)   continue;
         int flag = 0;
         for(int j=0; j<boom.length(); j++){
            if(ans[idx-j-1]!=boom[boom.length()-j-1]){
               flag = 1;
               break;
            }
         }
         if(flag==0){
            idx -= boom.length();
         }
      }
   }
   if(idx==0){
      cout<<"FRULA"<<'\n';
   }
   else{
      for(int i=0; i<idx; i++){
         cout<<ans[i];
      }
      cout<<'\n';
   }
   return 0;
}
