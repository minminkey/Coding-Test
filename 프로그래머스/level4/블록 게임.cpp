#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int N;
int cnt = 0;

void down(){
    for(int c=0; c<N; c++){
        for(int r=0; r<N; r++){
            if(board[r][c]>0)   break;
            board[r][c] = -1;
        }
    }
}

bool Select(int r, int c, int h, int w, int tnum){
    int flag = 0;
    int ncnt = 0;
    for(int i=r; i<r+h; i++){
        for(int j=c; j<c+w; j++){
            if(i<0||j<0||i>=N||j>=N){
                flag = 1;
                break;
            }
            if(!(board[i][j]==-1||board[i][j]==tnum)){
                flag = 1;
                break;
            }
            if(board[i][j]==tnum)   ncnt++;
        }
        if(flag == 1)   break;
    }
    if(flag == 0&&ncnt==4){
        // cout<<r<<' '<<c<<' '<<tnum<<endl;
        for(int i=r; i<r+h; i++){
            for(int j=c; j<c+w; j++){
                // cout<<board[i][j]<<' ';
                board[i][j] = 0;
            }
            cout<<endl;
        }
        return true;
    }
    return false;
}

bool check(){
    int first = cnt;
    for(int c=0; c<N; c++){
        for(int r=0; r<N; r++){
            if(board[r][c]>0){
                int tnum = board[r][c];
                if(Select(r,c,2,3,tnum))    cnt++;
                else if(Select(r,c,3,2,tnum))   cnt++;
                else if(Select(r-1,c,2,3,tnum))   cnt++;
                else if(Select(r-1,c,3,2,tnum))   cnt++;
                else if(Select(r-2,c,3,2,tnum))   cnt++;
                if(cnt!=first){
                    // cout<<r<<' '<<c<<endl;
                    return  true;
                }
            }
        }
    }
    return false;
}

int solution(vector<vector<int>> Board) {
    int answer = 0;
    board = Board;
    N = board.size();
    down();
    int f =0;
    while(check()){
        down();
        f++;
        // if(f>11)    break;
    }
    answer = cnt;
    return answer;
}