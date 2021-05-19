#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

char mp[6][6];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<vector<int>> nums;

void dfs(int now, int cnt, int scnt, vector<int> tmp){
    if(cnt==7&&scnt>=4){
        nums.push_back(tmp);
        return;
    }
    for(int i=now; i<=24; i++){
        tmp.push_back(i);
        if(mp[i/5][i%5]=='S')   dfs(i+1, cnt+1, scnt+1, tmp);
        else                    dfs(i+1, cnt+1, scnt, tmp);
        tmp.pop_back();
    }
}

bool ck(vector<int> num){
    int tmp[6][6] = {0, };
    int visit[6][6] = {0, };
    for(int i=0; i<num.size(); i++){
        int now = num[i];
        tmp[now/5][now%5] = 1;
    }
    queue<pair<int, int>> q;
    q.push({num[0]/5, num[0]%5});
    visit[num[0]/5][num[0]%5] = 1;
    int cnt = 1;
    while(!q.empty()){
        auto [r, c] = q.front();
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<0||nc<0||nr>=5||nc>=5)    continue;
            if(visit[nr][nc]==1||tmp[nr][nc]==0)    continue;
            visit[nr][nc] = 1;
            cnt++;
            q.push({nr, nc});
        }
        q.pop();
    }
    if(cnt>=7)  return true;
    else        return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>mp[i][j];
        }
    }
    vector<int> tmp;
    dfs(0, 0, 0, tmp);
    // cout<<nums.size()<<endl;
    for(int i=0; i<nums.size(); i++){
        if(ck(nums[i])){
            ans++;
        }
    }
    cout<<ans<<'\n';
	return 0;
}