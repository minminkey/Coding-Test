#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<string> mp;
struct Node{
    int r, c;
    int cnt;
};
int visit[1010][30];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   memset(visit, 0x3f3f3f3f, sizeof(visit));
   int n, m;
   cin>>m>>n;
   for(int i=0; i<n; i++){
       string s;
       cin>>s;
       mp.push_back(s);
   }
   queue<struct Node> q;
   for(int j=0; j<m; j++){
       if(mp[0][j]=='c'){
           struct Node tmp = {0,j,0};
        //    visit[0][j] = 1;
           q.push(tmp);
       }
   }
   int ans = 0x3f3f3f3f;
   while(!q.empty()){
       struct Node now = q.front();
       q.pop();
       int nr = now.r;
       int nc = now.c;
       int cnt = now.cnt;
       if(nr==n-1){
           ans = min(ans, cnt);
           continue;
       }
       if(cnt>visit[nr-1][nc])    continue;
       int idx = 0;
    //    cout<<"start : "<<nr<<' '<<nc<<' '<<cnt<<' '<<visit[nr-1][nc]<<endl;
       for(int c=nc; c<m; c++){
           if(mp[nr][c]=='x'||visit[nr][c]<=cnt+idx)   break;
           visit[nr][c] = cnt+idx;
           if(mp[nr+1][c]=='.'){
            //    cout<<nr+1<<' '<<c<<' '<<cnt+idx<<endl;
               struct Node next = {nr+1, c, cnt+idx};
               q.push(next);
           }
           idx++;
       }
       idx = 1;
       for(int c=nc-1; c>=0; c--){
           if(mp[nr][c]=='x'||visit[nr][c]<cnt+idx)   break;
           visit[nr][c] = cnt+idx;
           if(mp[nr+1][c]=='.'){
            //    cout<<nr+1<<' '<<c<<' '<<cnt+idx<<endl;
               struct Node next = {nr+1, c, cnt+idx};
               q.push(next);
           }
           idx++;
       }
   }
   cout<<ans<<'\n';
   return 0;
}