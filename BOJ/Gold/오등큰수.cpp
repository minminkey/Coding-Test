#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
   int n;
   cin>>n;
   vector<int> input;
   vector<int> f;
   stack<int> st;
   int ans[1000001] = {0, };
   int cnt[1000001] = {0, };
   for(int i=0; i<n; i++){
      int tmp;
      cin>>tmp;
      cnt[tmp]++;
      input.push_back(tmp);
   }
   for(int i=0; i<n; i++){
      f.push_back(cnt[input[i]]);
   }
   for(int i=0; i<n; i++){
      while(!st.empty()&&f[st.top()]<f[i]){
         ans[st.top()] = input[i];
         st.pop();
      }
      st.push(i);
   }
   while(!st.empty()){
      ans[st.top()] = -1;
      st.pop();
   }
   for(int i=0; i<n; i++){
      cout<<ans[i]<<' ';
   }
}