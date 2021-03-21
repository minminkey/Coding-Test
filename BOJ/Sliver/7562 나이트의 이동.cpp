#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
       int n, r, c, er, ec;
       int visit[301][301] = {0,};
       cin>>n;
       cin>>r>>c;
       cin>>er>>ec;
       queue<pair<int, pair<int, int>>> q;
       q.push({0, {r,c}});
       visit[r][c] = 1;
       int ans = 0;
        int flag = 0;
       while(!q.empty()){
           int nowR = q.front().second.first;
           int nowC = q.front().second.second;
           int cnt = q.front().first;
           q.pop();
            if(nowR==er&&nowC==ec){
                flag = 1;
                ans = cnt;
                break;
            }
           for(int i=0; i<8; i++){
               int nr = nowR + dr[i];
               int nc = nowC + dc[i];
               if(nr<0||nr>=n||nc<0||nc>=n||visit[nr][nc]==1)   continue;
               visit[nr][nc] = 1;
                q.push({cnt+1, {nr, nc}});
           }
           if(flag == 1)    break;
       }
       if(flag==1){
           cout<<ans<<'\n';
       }
       else{
           cout<<-1<<'\n';
       }
   }
   return 0;
}
