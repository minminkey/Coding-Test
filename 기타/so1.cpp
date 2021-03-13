#include<iostream>
#include<queue>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int mp[11][11] = {0,};

int main(){
    int T;
    int n,m;
    cin>>T;
    while(T--){
        cin>>m>>n;
        int sr, sc;
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                int k;
                cin>>k;
                if(k==3){
                    sr = i;
                    sc = j;
                }
                mp[i][j] = k;
            }
        }
        int visit[11][11] = {0,};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visit[sr][sc] = 1;
        int flag = 0;
        int flag1 = 0;
        int flag2 = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // cout<<r<<' '<<c<<endl;
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0||nr>=m||nc<0||nc>=n)    continue;
                if(mp[nr][nc]==1)               continue;
                if(visit[nr][nc]==1)continue;
                visit[nr][nc] = 1;
                if(mp[nr][nc]==2&&flag1==0){
                    flag++;
                    flag1 = 1;
                }
                if(mp[nr][nc]==4&&flag2==0){
                    flag++;
                    flag2 = 1;
                }
                q.push({nr, nc});
            }
        }
        if(flag>=2){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
    return 0;
}