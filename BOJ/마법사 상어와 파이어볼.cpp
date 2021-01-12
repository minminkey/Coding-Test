#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, K, M;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
struct Fireball{
    int r;
    int c;
    int m;
    int s;
    int d;
    bool live;
};
vector <int> mp[60][60];
vector <Fireball> fireball;

void move(){
    for(int i=0; i<fireball.size(); i++){
        if(fireball[i].live==false)    continue;
        int nr = fireball[i].r;
        int nc = fireball[i].c;
        int d = fireball[i].d;
        // mp[nr][nc].pop_back();
        // cout<<i+1<<" : "<<nr<<' '<<nc<<endl;
        for(int j=0; j<fireball[i].s; j++){
            nr = nr + dr[d];
            nc = nc + dc[d];
            if(nr<0)    nr = N-1;
            if(nc<0)    nc = N-1;
            if(nr>=N)   nr = 0;
            if(nc>=N)   nc = 0;
            // cout<<nr<<' '<<nc<<endl;
        }
        fireball[i].r = nr;
        fireball[i].c = nc;
        // cout<<i+1<<" : "<<nr<<' '<<nc<<endl;
        mp[nr][nc].push_back(i);
    }
}
void merge(){
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(mp[r][c].size()<2)   continue;
            int m = 0;
            int n = mp[r][c].size();
            // cout<<"n : "<<mp[r][c].size()<<endl;;
            int s = 0;
            int flag1 = 1;                          //짝수 나오면 0
            int flag2 = 1;     
            int d = 1;                     //홀수 나오면 0
            for(int i=0; i<mp[r][c].size(); i++){
                // cout<<mp[r][c][i]+1<<endl;
                m += fireball[mp[r][c][i]].m;
                s += fireball[mp[r][c][i]].s;
                if(fireball[mp[r][c][i]].d%2==0)    flag1 = 0;
                else                                flag2 = 0;
                fireball[mp[r][c][i]].live = false;
            }
            mp[r][c].clear();
            m = m/5;
            s = s/n;
            if(flag1==1||flag2==1) d = 0;
            // cout<<"small : "<<m<<' '<<s<<' '<<d<<endl;
            if(m==0)    continue;
            for(int i=0; i<4; i++){
                struct Fireball tmp;
                tmp.r = r;
                tmp.c = c;
                tmp.m = m;
                tmp.s = s;
                tmp.d = d;
                tmp.live = true;
                d += 2;
                mp[r][c].push_back(fireball.size());
                fireball.push_back(tmp);
            }
        }
    }
}
int main(){
    cin>>N>>M>>K;
    int ans=0;
    for(int i=0; i<M; i++){
        struct Fireball f;
        int r,c;
        cin>>r>>c>>f.m>>f.s>>f.d;
        f.r = r-1;
        f.c = c-1;
        f.live = true;
        fireball.push_back(f);
        mp[f.r][f.c].push_back(i);
    }
    int cnt=0;
    while(cnt<K){
        cnt++;
        // cout<<"CNT : "<<cnt<<endl;
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                mp[r][c].clear();
            }
        }
        move();
        merge();
        // cout<<endl;
    }
    for(int i=0; i<fireball.size(); i++){
        if(fireball[i].live != true)   continue;
        ans += fireball[i].m;
    }
    cout<<ans<<'\n';
}
