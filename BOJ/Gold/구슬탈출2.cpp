#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <tuple>
#include <string.h>
using namespace std;

int N, M;
char mp[15][15] = {0,};
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

tuple<int, int, int> go(int r, int c, int kr, int kc, int d){
   while(mp[r][c]=='.'){
      int nr = r + dr[d];
      int nc = c + dc[d];
      if(nr<0||nc<0||nr>=N||nc>=M)  return make_tuple(r, c, 0);
      if(nr==kr&&nc==kc)            return make_tuple(r, c, 0);
      if(mp[nr][nc]=='O')           return make_tuple(-1, -1, 1);
      else if(mp[nr][nc]=='#')      return make_tuple(r, c, 0);
      r = nr;
      c = nc;
   }
   return make_tuple(r,c,-1);
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>N>>M;
   int rR, cR, rB, cB;
   for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
         cin>>mp[i][j];
         if(mp[i][j]=='R'){
            mp[i][j] = '.';
            rR = i;
            cR = j;
         }
         if(mp[i][j]=='B'){
            mp[i][j] = '.';
            rB = i;
            cB = j;
         }
      }
   }
   queue<tuple<int, int, int, int, int, int>> q;
   q.push({rR, cR, rB, cB, 0, -1});
   while(!q.empty()){
      auto [rr, cr, rb, cb, cnt, pre] = q.front();
      q.pop();
      for(int i=0; i<4; i++){
         if(pre!=-1&&(pre+2)%4==i)  continue;
         if(i==0){
            if(rr<rb){
               auto [nrr, ncr, flag2] = go(rr, cr, -1, -1, i);
               auto [nrb, ncb, flag1] = go(rb, cb, nrr, ncr, i);
               if(flag1==1)   continue;
               if(flag2==1){
                  cout<<cnt+1<<'\n';
                  return 0;
               }
               if(cnt+1>=10)   continue;
               q.push(make_tuple(nrr, ncr, nrb, ncb, cnt+1, i));
            }
            else{
               auto [nrb, ncb, flag1] = go(rb, cb, -1, -1, i);
               if(flag1==1)   continue;
               auto [nrr, ncr, flag2] = go(rr, cr, nrb, ncb, i);
               if(flag2==1){
                  cout<<cnt+1<<'\n';
                  return 0;
               }
               if(cnt+1>=10)   continue;
               q.push(make_tuple(nrr, ncr, nrb, ncb, cnt+1, i));
            }
         }
         else if(i==1){
            if(cr>cb){
               auto [nrr, ncr, flag2] = go(rr, cr, -1, -1, i);
               auto [nrb, ncb, flag1] = go(rb, cb, nrr, ncr, i);
               if(flag1==1)   continue;
               if(flag2==1){
                  cout<<cnt+1<<'\n';
                  return 0;
               }
               if(cnt+1>=10)   continue;
               q.push(make_tuple(nrr, ncr, nrb, ncb, cnt+1, i));
            }
            else{
               auto [nrb, ncb, flag1] = go(rb, cb, -1, -1, i);
               if(flag1==1)   continue;
               auto [nrr, ncr, flag2] = go(rr, cr, nrb, ncb, i);
               if(flag2==1){
                  cout<<cnt+1<<'\n';
                  return 0;
               }
               if(cnt+1>=10)   continue;
               q.push(make_tuple(nrr, ncr, nrb, ncb, cnt+1, i));
            }
         }
         else if(i==2){
            if(rr>rb){
               auto [nrr, ncr, flag2] = go(rr, cr, -1, -1, i);
               auto [nrb, ncb, flag1] = go(rb, cb, nrr, ncr, i);
               if(flag1==1)   continue;
               if(flag2==1){
                  cout<<cnt+1<<'\n';
                  return 0;
               }
               if(cnt+1>=10)   continue;
               q.push(make_tuple(nrr, ncr, nrb, ncb, cnt+1, i));
            }
            else{
               auto [nrb, ncb, flag1] = go(rb, cb, -1, -1, i);
               if(flag1==1)   continue;
               auto [nrr, ncr, flag2] = go(rr, cr, nrb, ncb, i);
               if(flag2==1){
                  cout<<cnt+1<<'\n';
                  return 0;
               }
               if(cnt+1>=10)   continue;
               q.push(make_tuple(nrr, ncr, nrb, ncb, cnt+1, i));
            }
         }
         else{
            if(cr<cb){
               auto [nrr, ncr, flag2] = go(rr, cr, -1, -1, i);
               auto [nrb, ncb, flag1] = go(rb, cb, nrr, ncr, i);
               if(flag1==1)   continue;
               if(flag2==1){
                  cout<<cnt+1<<'\n';
                  return 0;
               }
               if(cnt+1>=10)   continue;
               q.push(make_tuple(nrr, ncr, nrb, ncb, cnt+1, i));
            }
            else{
               auto [nrb, ncb, flag1] = go(rb, cb, -1, -1, i);
               if(flag1==1)   continue;
               auto [nrr, ncr, flag2] = go(rr, cr, nrb, ncb, i);
               if(flag2==1){
                  cout<<cnt+1<<'\n';
                  return 0;
               }
               if(cnt+1>=10)   continue;
               q.push(make_tuple(nrr, ncr, nrb, ncb, cnt+1, i));
            }
         }
      }
   }
   cout<<-1<<'\n';
   return 0;
}