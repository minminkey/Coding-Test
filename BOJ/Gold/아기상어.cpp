#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <tuple>
#include <string.h>
using namespace std;

int N, M;
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
vector<vector<int>> board;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
   auto [ar, ac, k] = a;
   auto [br, bc, f] = b;
   if(ar==br){
      return ac<bc;
   }
   return ar<br;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>N;
   int ans = 0;
   int sr, sc;
   int now = 2, cnt = 0;
   for(int i=0; i<N; i++){
      vector<int> tmp;
      for(int j=0; j<N; j++){
         int t;
         cin>>t;
         if(t==9){
            sr = i;
            sc = j;
            t = 0;
         }
         tmp.push_back(t);
      }
      board.push_back(tmp);
   }
   while(1){
      queue<tuple<int, int, int>> q;
      vector<tuple<int, int, int>> fish;
      int visit[21][21] = {0,};
      visit[sr][sc] = 1;
      q.push({sr, sc, 0});
      int limit = 10000;
      int flag = 0;
      while(!q.empty()){
         auto [r, c, t] = q.front();
         q.pop();
         for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(t+1>limit)                 continue;
            if(nr<0||nc<0||nr>=N||nc>=N)  continue;
            if(visit[nr][nc]==1)          continue;
            if(board[nr][nc]>now)         continue;
            visit[nr][nc] = 1;
            if(board[nr][nc]!=0&&board[nr][nc]<now){
               limit = t+1;
               fish.push_back({nr, nc, t+1});
            }
            else  q.push({nr, nc, t+1});
         }
      }
      sort(fish.begin(), fish.end(), cmp);
      if(fish.size()>0){
         auto [fr, fc, ft] = fish[0];
         board[fr][fc] = 0;
         cnt++;
         sr = fr;
         sc = fc;
         ans += ft;
         flag = 1;
         if(cnt==now){
            cnt = 0;
            now++;
         }
      }
      if(flag==0){
         break;
      }
   }
   cout<<ans<<'\n';
   return 0;
}