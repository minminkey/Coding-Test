#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int N;
int Point = 0;
int cnt = 0;
int green[6][4];
int blue[4][6];
struct Block{
    int t;
    int x;
    int y;
};
struct Block block[10001];

void down(int R){
    for(int r = R; r>0; r--){
        for(int c=0; c<4; c++){
            green[r][c] = green[r-1][c];
        }
    }
    for(int c=0; c<4; c++){
        green[0][c] = 0;
    }
}
bool g_ck(){                    //한 행이 꽉찬거 있나 확인
    int flag2 = 0;
    for(int r=5; r>=0; r--){
        int flag = 0;
        for(int c=0; c<4; c++){
            if(green[r][c]==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            for(int c=0; c<4; c++){
                green[r][c] = 0;
            }
            down(r);
            Point++;
            flag2 = 1;
        }
    }
    if(flag2==1)    return true;
    else            return false;
}
void right(int C){
    for(int c=C; c>0; c--){
        for(int r=0; r<4; r++){
            blue[r][c] = blue[r][c-1];
        }
    }
    for(int r=0; r<4; r++){
        blue[r][0] = 0;
    }
}
bool b_ck(){                    //한 열이 꽉찬거 있나 확인
    int flag2 = 0;
    for(int c=5; c>=0; c--){
        int flag = 0;
        for(int r=0; r<4; r++){
            if(blue[r][c]==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            for(int r=0; r<4; r++){
                blue[r][c]=0;
            }
            Point++;
            right(c);
            flag2 = 1;
        }
    }
    if(flag2==1)    return true;
    else            return false;
}
void g_move(){
    while(g_ck()){
        // down();
    }
}
void b_move(){
    while(b_ck()){
        // right();
    }
}
void g_delete(){                    //0,1행에 블럭있나 확인 후 삭제
    int temp = 0;
    for(int r=0; r<2; r++){
        for(int c=0; c<4; c++){
            if(green[r][c]!=0){
                temp++;
                break;
            }
        }
    }
    for(int r=5; r>=2; r--){
        for(int c=0; c<4; c++){
            green[r][c] = green[r-temp][c];
        }
    }
    for(int r=0; r<2; r++){
        for(int c=0; c<4; c++){
            green[r][c] = 0;
        }
    }    
}
void b_delete(){
    int temp = 0;
    for(int c=0; c<2; c++){
        for(int r=0; r<4; r++){
            if(blue[r][c]!=0){
                temp++;
                break;
            }
        }
    }
    for(int c=5; c>=2; c--){
        for(int r=0; r<4; r++){
            blue[r][c] = blue[r][c-temp];
        }
    }
    for(int c=0; c<2; c++){
        for(int r=0; r<4; r++){
            blue[r][c] = 0;
        }
    }
}
void g_put(int t, int x, int y){
    if(t==1){
        green[0][y] = 1;
        for(int r=1; r<=5; r++){
            if(green[r][y]==0){
                green[r-1][y] = 0;
                green[r][y] = 1;
            }
            else break;
        }
    }
    else if(t==2){
        green[0][y] = 2;
        green[0][y+1] = 2;
        for(int r=1; r<=5; r++){
            if(green[r][y]==0&&green[r][y+1]==0){
                green[r-1][y] = 0;
                green[r-1][y+1] = 0;
                green[r][y] = 2;
                green[r][y+1] = 2;
            }
            else break;
        }
    }
    else if(t==3){
        green[0][y] = 3;
        green[1][y] = 3;
        for(int r=1; r<5; r++){
            if(green[r+1][y]==0){
                green[r-1][y] = 0;
                green[r+1][y] = 3;
            }
            else break;
        }
    }
}
void b_put(int t, int x, int y){
    if(t==1){
        blue[x][0] = 1;
        for(int c=1; c<=5; c++){
            if(blue[x][c]==0){
                blue[x][c-1] = 0;
                blue[x][c] = 1;
            }
            else break;
        }
    }
    else if(t==2){
        blue[x][0] = 2;
        blue[x][1] = 2;
        for(int c=1; c<5; c++){
            if(blue[x][c+1]==0){
                blue[x][c-1] = 0;
                blue[x][c+1] = 2;
            }
            else break;
        }
    }
    else if(t==3){
        blue[x][0] = 3;
        blue[x+1][0] = 3;
        for(int c=1; c<=5; c++){
            if(blue[x][c]==0&&blue[x+1][c]==0){
                blue[x][c-1] = 0;
                blue[x+1][c-1] = 0;
                blue[x][c] = 3;
                blue[x+1][c] = 3;
            }
            else break;
        }
    }
}
void ct(){
    for(int r=0; r<6; r++){
        for(int c=0; c<4; c++){
            if(green[r][c]!=0)  cnt++;
        }
    } 
    for(int c=0; c<6; c++){
        for(int r=0; r<4; r++){
            if(blue[r][c]!=0)  cnt++;
        }
    }
}
void Solution(){
    for(int i=0; i<N; i++){
        g_put(block[i].t,block[i].x, block[i].y);
        b_put(block[i].t,block[i].x, block[i].y);
        g_move();
        b_move();
        g_delete();
        b_delete();
    }
    ct();
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>block[i].t>>block[i].x>>block[i].y;
    }
    Solution();
    cout<<Point<<'\n'<<cnt<<'\n';
}
