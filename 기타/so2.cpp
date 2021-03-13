#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int step[100001];
int dp[100001];
int ans = 0;

void go(int now, vector<int> pre, int visit[]){
    int next = now + step[now];
    if(dp[next] != 0){
        while(!pre.empty()){
            dp[pre.back()] = -1;
            pre.pop_back();
        }
        return;
    }
    else if(visit[next] != 0){
        int d = pre.size() - visit[next] + 1;
        ans = max(ans, d);
        while(pre.back()!=next){
            dp[pre.back()] = d;
            pre.pop_back();
        }
        dp[pre.back()] = d;
        pre.pop_back();
        while(!pre.empty()){
            dp[pre.back()] = -1;
            pre.pop_back();
        }
        return;
    }
    pre.push_back(next);
    visit[next] = pre.size();
    go(next, pre, visit);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        step[i] = k;
    }
    for(int i=0; i<n; i++){
        if(dp[i]!=0)    continue;
        vector<int> pre;
        int visit[100001] = {0,};
        pre.push_back(i);
        visit[i] = 1;
        go(i, pre, visit);
    }
    cout<<ans<<'\n';
    return 0;
}