#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
vector<vector<int>> ans;
vector<vector<int>> mp;
vector<int> row[10];
vector<int> col[10];
vector<int> ses[10];
int flag = 0;

void findAll(int r){
   if(flag==1) return;
   for(int i=r; i<9; i++){
      for(int j=0; j<9; j++){
         if(mp[i][j]==0){
            for(int k=1; k<=9; k++){
               if(flag==1) return;
               if(find(row[i].begin(), row[i].end(), k)==row[i].end()&&find(col[j].begin(), col[j].end(), k)==col[j].end()&&find(ses[(i/3)*3+j/3].begin(), ses[(i/3)*3+j/3].end(), k)==ses[(i/3)*3+j/3].end()){
                  row[i].push_back(k);
                  col[j].push_back(k);
                  ses[(i/3)*3+j/3].push_back(k);
                  mp[i][j] = k;
                  findAll(i);
                  mp[i][j] = 0;
                  ses[(i/3)*3+j/3].pop_back();
                  col[j].pop_back();
                  row[i].pop_back();
               }
            }
            if(i==8&&j==8){
              ans = mp;
               flag = 1;
               return;
            }
            return;
         }
      if(i==8&&j==8){
            ans = mp;
            flag = 1;
            return;
         }
      }
   }
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   for(int i=0; i<9; i++){
      string s;
      cin>>s;
      vector<int> tmp;
      for(int j=0; j<9; j++){
         tmp.push_back(s[j] - '0');
      }
      mp.push_back(tmp);
   }
   for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
         if(mp[i][j]!=0){
            row[i].push_back(mp[i][j]);
            col[j].push_back(mp[i][j]);
            ses[(i/3)*3+j/3].push_back(mp[i][j]);
         }
      }
   }
   findAll(0);
   for(int i=0; i<9; i++){
      for(int j=0; j<9; j++){
         cout<<ans[i][j];
      }
      cout<<'\n';
   }
   return 0;
}
