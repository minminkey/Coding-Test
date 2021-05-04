#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <string.h>
using namespace std;

int N;
vector<int> want[401];
vector<int> order;
int mp[21][21];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N*N; i++){
        int num, a,b,c,d;
        cin>>num>>a>>b>>c>>d;
        order.push_back(num);
        want[num].push_back(a);
        want[num].push_back(b);
        want[num].push_back(c);
        want[num].push_back(d);
    }
    for(int i=0; i<order.size(); i++){
        int now = order[i];
        int tr = N;
        int tc = N;
        int tcnt = -1;
        int tbcnt = -1;
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                if(mp[r][c]!=0) continue;
                int cnt = 0;
                int bcnt = 0;
                for(int d=0; d<4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr<0||nc<0||nr>=N||nc>=N)    continue;
                    if(mp[nr][nc]==0)   bcnt++;
                    for(int i=0; i<4; i++){
                        if(mp[nr][nc]==want[now][i]){
                            cnt++;
                            break;
                        }
                    }
                }
                if(tcnt<cnt){
                    tcnt = cnt;
                    tr = r;
                    tc = c;
                    tbcnt = bcnt;
                }
                else if(tcnt==cnt){
                    if(tbcnt<bcnt){
                        tbcnt = bcnt;
                        tr = r;
                        tc = c;
                    }
                    else if(tbcnt==bcnt){
                        if(tr>r){
                            tr = r;
                            tc = c;
                        }
                        else if(tr==r){
                            tc = min(tc, c);
                        }
                    }
                }
            }
        }
        mp[tr][tc] = now;
    }
    int ans = 0;
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            int cnt = 0;
            int now = mp[r][c];
            for(int d=0; d<4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr<0||nc<0||nr>=N||nc>=N)    continue;
                for(int i=0; i<4; i++){
                    if(mp[nr][nc]==want[now][i]){
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt==1)      ans += 1;
            else if(cnt==2) ans += 10;
            else if(cnt==3) ans += 100;
            else if(cnt==4) ans += 1000;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
