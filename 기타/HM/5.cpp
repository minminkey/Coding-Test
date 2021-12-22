#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dr[4] = {-1, 1, 1, -1};
int dc[4] = {1, 1, -1, -1};
int N;

vector<string> board;

int ck(int r, int c){
    char now = board[r][c];
    int cnt = 0;
    while(1){
        cnt++;
        int flag = 0;
        for(int d=0; d<4; d++){
            int nr = r + dr[d]*cnt;
            int nc = c + dc[d]*cnt;
            if(nr<0||nc<0||nr>=N||nc>=N||board[nr][nc] != now){
                flag = 1;
                break;
            }
        }
        if(flag)    break;
    }
    return cnt-1;
}

int solution(vector<string> Board) {
    int answer = 0;
    board = Board;
    N = board.size();
    int s = (N-1)/2;
    while(s>0){
        for(int r=s; r<N-s; r++){
            for(int c=s; c<N-s; c++){
                if(ck(r,c) == s){
                    return s*2+1;
                }
            }
        }
        s--;
    }
    return 0;
}