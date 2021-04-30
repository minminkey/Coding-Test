#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<int> edge[201];
int visit[201];
int n, m;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m;
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           int tmp;
           cin>>tmp;
           if(tmp==1)   edge[i+1].push_back(j+1);
       }
   }
   for(int i=1; i<=n; i++){
       if(visit[i]!=0)  continue;
       queue<int> q;
       q.push(i);
       visit[i] = i;
       while(!q.empty()){
           int now = q.front();
           q.pop();
           for(int j=0; j<edge[now].size(); j++){
               int next = edge[now][j];
               if(visit[next]!=0)   continue;
               visit[next] = i;
               q.push(next);
           }
       }
   }
   int start;
   cin>>start;
   int foo = visit[start];
   int flag = 0;
   for(int i=0; i<m-1; i++){
       int now;
       cin>>now;
       if(visit[now]!=foo){
           flag = 1;
       }
   }
   if(flag == 0){
       cout<<"YES"<<'\n';
   }
   else cout<<"NO"<<'\n';
   return 0;
}
