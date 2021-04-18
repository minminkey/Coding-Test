#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <tuple>
#include <string.h>
using namespace std;

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

int R, C;
int visit[1501][1501];
char lack[1501][1501];
queue<pair<int, int>> w, nw;
queue<pair<int, int>> s, ns;

bool swanBFS(){
   while(!s.empty()){
      auto [r, c] = s.front();
      s.pop();
      for(int i=0; i<4; i++){
         int nr = r+dr[i];
         int nc = c+dc[i];
         if(nr<0||nc<0||nr>=R||nc>=C)  continue;
         if(visit[nr][nc]==1)          continue;
         visit[nr][nc] = 1;
         if(lack[nr][nc]=='.')         s.push({nr, nc});
         else if(lack[nr][nc]=='X')    ns.push({nr, nc});
         else                          return true;
      }  
   }
   return false;
}

void waterBFS(){
   while(!w.empty()){
      auto [r, c] = w.front();
      w.pop();
      for(int i=0; i<4; i++){
         int nr = r+dr[i];
         int nc = c+dc[i];
         if(nr<0||nc<0||nr>=R||nc>=C)  continue;
         else if(lack[nr][nc]=='X'){
            lack[nr][nc] = '.';
            nw.push({nr, nc});
         }
      }  
   }
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>R>>C;
   int sr, sc;
   int idx = 0;
   for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
         cin>>lack[i][j];
         if(lack[i][j]!='X')  w.push({i, j});
         if(lack[i][j]=='L'){
            sr = i;
            sc = j;
         }
      }
   }
   int ans = 0;
   s.push({sr, sc});
   visit[sr][sc] = 1;
   while(!swanBFS()){
      waterBFS();
      w = nw;
      s = ns;
      while(!ns.empty()) ns.pop();
      while(!nw.empty()) nw.pop();
      ans++;
   }
   cout<<ans<<'\n';
   return 0;
}