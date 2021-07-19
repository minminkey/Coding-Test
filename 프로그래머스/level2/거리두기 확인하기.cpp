#include <string>
#include <iostream>
#include <vector>

using namespace std;

int board[6][6];

int dr[] = {-1, 0, 0, 1, 1, 2};
int dc[] = {1, 1, 2, 1, 0, 0};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0; i<places.size(); i++){
        int flag = 1;
        for(int j=0; j<places[i].size(); j++){
            for(int s=0; s<places[i][j].length(); s++){
                if(places[i][j][s] == 'O')      board[j][s] = 0;
                else if(places[i][j][s] == 'P') board[j][s] = 1;
                else                            board[j][s] = 2;
            }
        }
        for(int r=0; r<5; r++){
            if(flag == 0)   break;
            for(int c=0; c<5; c++){
                if(flag == 0)   break;
                if(board[r][c] == 1){
                    for(int d=0; d<6; d++){
                        int nr = r+dr[d];
                        int nc = c+dc[d];
                        if(nr<0||nc<0||nr>=5||nc>=5)    continue;
                        if(board[nr][nc]!=1)            continue;
                        if(d == 0){
                            if(board[r-1][c] != 2 || board[r][c+1] != 2)    flag = 0;
                        }
                        else if(d == 1){
                            flag = 0;
                        }
                        else if(d == 2){
                            if(board[r][c+1] != 2)  flag = 0;
                        }
                        else if(d == 3){
                            if(board[r][c+1] != 2 || board[r+1][c] != 2)    flag = 0;
                        }
                        else if(d == 4){
                            flag = 0;
                        }
                        else{
                            if(board[r+1][c] != 2)  flag = 0;
                        }
                    }              
                }
            }
        }
        answer.push_back(flag);
    }
    return answer;
}