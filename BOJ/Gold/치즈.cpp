#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<vector<int>> mp;
int n, m;


bool airCheck(){
    int visit[101][101] = {0,};
    visit[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0,0});
    mp[0][0] = -1;
    int flag = 0;
    while(!q.empty()){
       int r = q.front().first;
       int c = q.front().second;
       q.pop();
       for(int i=0; i<4; i++){
          int nr = r + dr[i];
          int nc = c + dc[i];
          if(nr<0||nr>=n||nc<0||nc>=m||visit[nr][nc]==1) continue;
          if(mp[nr][nc]==1){
             flag = 1;
             continue;
          }
          q.push({nr,nc});
          visit[nr][nc] = 1;
          mp[nr][nc] = -1;
       }
    }
   if(flag == 1)  return true;
   else           return false;
}

int main(){
   ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>n>>m;
   for(int i=0; i<n; i++){
       vector<int> tmp;
       for(int j=0; j<m; j++){
           int t;
           cin>>t;
           tmp.push_back(t);
       }
       mp.push_back(tmp);
   }
   vector<vector<int>> copy;
   int ans = 0;
   while(airCheck()){
      copy = mp;
       for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            if(copy[i][j]==1){
               int cnt = 0;
               for(int d=0; d<4; d++){
                  int nr = i + dr[d];
                  int nc = j + dc[d];
                  if(copy[nr][nc]==-1) cnt++;
               }
               if(cnt>=2){
                  mp[i][j] = -1;
               }
            }
         }
      }
      ans++;
   }
   cout<<ans<<'\n';
   return 0;
}