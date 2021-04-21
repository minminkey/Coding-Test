#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int ckRow(char mp[4][4], int idx){
    char now = mp[idx][0];
    if(now =='T')   now = mp[idx][1];
    if(now=='.')    return -1;
    for(int c=0; c<4; c++){
        if(mp[idx][c]=='T') continue;
        if(mp[idx][c]!=now) return -1;
    }
    if(now=='O')    return 1;
    else            return 2;
}
int ckCol(char mp[4][4], int idx){
    char now = mp[0][idx];
    if(now =='T')   now = mp[1][idx];
    if(now=='.')    return -1;
    for(int r=0; r<4; r++){
        if(mp[r][idx]=='T') continue;
        if(mp[r][idx]!=now) return -1;
    }
    if(now=='O')    return 1;
    else            return 2;
}
int ckCross(char mp[4][4], int idx){
    char now;
    if(idx==0){
        now = mp[0][0];
        if(mp[0][0]=='T'){
            now = mp[1][1];
        }
        if(now=='.')    return -1;
        for(int rc=0; rc<4; rc++){
            if(mp[rc][rc]=='T') continue;
            if(mp[rc][rc]!=now) return -1;
        }
    }
    else{
        now = mp[3][0];
        if(mp[3][0]=='T'){
            now = mp[2][1];
        }   
        if(now=='.')    return -1;
        for(int rc=0; rc<4; rc++){
            if(mp[3-rc][rc]=='T')   continue;
            if(mp[3-rc][rc]!=now)   return -1;
        }
    }
    if(now=='.')    return -1;
    else if(now=='O')    return 1;
    else            return 2;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    int TC;
    cin>>TC;
    char ans[3] = {' ', 'O', 'X'};
    for(int t=1; t<=TC; t++){
        char mp[4][4];
        int cnt = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin>>mp[i][j];
                if(mp[i][j]!='.')   cnt++;
            }
        }
        int flag = 0;
        for(int i=0; i<4; i++){
            int r = ckRow(mp, i);
            int c = ckCol(mp, i);
            if(r!=-1){
                flag = r;
                break;
            }
            if(c!=-1){
                flag = c;
                break;
            }   
        }
        for(int i=0; i<2; i++){
            int x = ckCross(mp, i);
            if(x!=-1){
                flag = x;
                break;
            }
        }
        if(flag!=0){
            printf("#%d %c won\n",t, ans[flag]);
        }
        else if(cnt==16){
            printf("#%d Draw\n",t);
        }
        else{
            printf("#%d Game has not completed\n",t);
        }
    }
	return 0;
}