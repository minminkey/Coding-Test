#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int visit[500001][2];
int bro[500001];
int INF = 0X3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // memset(bro, -1, sizeof(bro));
    memset(visit, -1, sizeof(visit));
    int n, k;
    cin>>n>>k;
    if(n==k){
        cout<<0<<'\n';
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({n,0});
    while(!q.empty()){
        auto [now, ti] = q.front();
        q.pop();
        // if(bro[now]==ti){
        //     cout<<ti<<'\n';
        //     return 0;
        // }
        if(now>500000||now<0)   continue;
        if(visit[now][ti%2]!=-1) continue;
        visit[now][ti%2] = ti;
        q.push({now-1, ti+1});
        q.push({now+1, ti+1});
        q.push({now*2, ti+1});
    }
    int t = 0;
    while(k<=500000){
        if(visit[k][t%2]<=t){
            cout<<t<<'\n';
            return 0;
        }
        t++;
        k += t;
    }
    cout<<-1<<'\n';
	return 0;
}