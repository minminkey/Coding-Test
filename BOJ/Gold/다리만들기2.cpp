#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int num = 1;
int ans = 0;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<vector<int>> map(15, vector<int>(15));
struct Info{
    int r;
    int c;
    int d;
    int dist;
};

void classfy(){
    vector<vector<int>> visit(15, vector<int>(15));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==1&&visit[i][j]==0){
                queue<pair<int, int>> q;
                visit[i][j] = 1;
                map[i][j] = num;
                q.push({i, j});
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nr = r+dr[k];
                        int nc = c+dc[k];
                        if(nr>=0&&nr<N&&nc>=0&&nc<M&&map[nr][nc]>0&&visit[nr][nc]==0){
                            visit[nr][nc] = 1;
                            map[nr][nc] = num;
                            q.push({nr, nc});
                        }
                    }
                }
                num++;
            }
        }
    }
}
void pushMain(queue<struct Info> &m, int r, int c){
    queue<struct Info> q = m;
    vector<vector<int>> visit(15, vector<int>(15));
    struct Info t = {r,c,-1,0};
    m.push(t);
    q.push(t);
    visit[r][c] = 1;
    while(!q.empty()){
        int sr = q.front().r;
        int sc = q.front().c;
        q.pop();
         for(int k=0; k<4; k++){
            int nr = sr+dr[k];
            int nc = sc+dc[k];
            if(nr>=0&&nr<N&&nc>=0&&nc<M&&map[nr][nc]>0&&visit[nr][nc]==0){
                visit[nr][nc] = 1;
                struct Info tmp = {nr, nc, -1,0};
                q.push(tmp);
                m.push(tmp);
            }
        }
    }
}
void makeBridge(int r, int c){
    int ck[10] = {0, };
    ck[map[r][c]] = 1;
    queue<struct Info> m;
    int cnt = 1;
    int flag = 1;
    pushMain(m, r, c);
    while(cnt<num){
        queue<struct Info> q = m;
        while(!q.empty()){
            flag = 1;
            int sr = q.front().r;
            int sc = q.front().c;
            int sd = q.front().d;
            int sdist = q.front().dist;
            q.pop();
            if(sd==-1){
                for(int i=0; i<4; i++){
                    int nr = sr+dr[i];
                    int nc = sc+dc[i];
                    int nd = i;
                    int ndist = sdist+1;
                    if(nr<0||nr>=N||nc<0||nc>=M)    continue;
                    if(map[nr][nc]<=0){
                        struct Info tmp = {nr, nc, nd, ndist};
                        q.push(tmp);
                    }
                    flag = 0;
                }
            }
            else{
                int nr = sr+dr[sd];
                int nc = sc+dc[sd];
                int nd = sd;
                int ndist = sdist+1;
                if(nr<0||nr>=N||nc<0||nc>=M)    continue;
                if(map[nr][nc]<=0){
                    struct Info tmp = {nr, nc, nd, ndist};
                    flag = 0;
                    q.push(tmp);
                }
                else{
                    if(ndist<3||ck[map[nr][nc]]==1) continue;
                    ck[map[nr][nc]] = 1;
                    pushMain(m, nr, nc);
                    int pr = nr;
                    int pc = nc;
                    ans += sdist;
                    cnt++;
                    flag = 0;
                    break;
                }
            }
        }
        if(q.empty()&&flag==1){
            break;
        };
    }
    if(cnt!=num)    ans = -1;
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    classfy();
    num--;
    for(int i=0; i<N; i++){
        int flag=0;
        for(int j=0; j<M; j++){
            if(map[i][j]!=0){
                makeBridge(i,j);
                flag=1;
                break;
            }
        }
        if(flag==1) break;
    }
    cout<<ans<<endl;
}