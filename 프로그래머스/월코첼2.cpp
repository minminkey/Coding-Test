#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

typedef struct{
    int type;
    int out[4];
} Node;
Node mp[501][501];

int go(int r, int c, int d){
    // cout<<r<<' '<<c<<' '<<d<<endl;
    int nd = d;
    if(mp[r][c].type == 2){
        nd--;
        if(nd<0)    nd = 3;
    }
    else if(mp[r][c].type == 3){
        nd = (nd+1)%4;
    }
    if(mp[r][c].out[nd] == 1){
        return 0;        
    }
    mp[r][c].out[nd] = 1;
    int nr = r + dr[nd];
    int nc = c + dc[nd];
    // cout<<nr<<' '<<nc<<' '<<R<<' '<<C<<endl;
    if(nr<0)    nr = R-1;
    else if(nr>=R)  nr = 0;
    if(nc<0)    nc = C-1;
    else if(nc>=C)  nc = 0;
    // cout<<nr<<' '<<nc<<endl;
    return 1+go(nr, nc, nd);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    R = grid.size();
    C = grid[0].length();
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(grid[r][c] == 'S'){
                mp[r][c].type = 1;
            }
            else if(grid[r][c] == 'L'){
                mp[r][c].type = 2;
            }
            else{
                mp[r][c].type = 3;
            }
        }
    }
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            for(int d=0; d<4; d++){
                if(mp[r][c].out[d]==0){
                    // cout<<r<<' '<<c<<' '<<d<<" start!"<<endl;
                    int nd = d;
                    if(mp[r][c].type == 3){
                        nd--;
                        if(nd<0)    nd = 3;
                    }
                    else if(mp[r][c].type == 2){
                        nd = (nd+1)%4;
                    }
                    answer.push_back(go(r,c,nd));
                    // cout<<answer[answer.size()-1]<<endl;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}