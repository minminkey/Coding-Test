#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt;

bool find(vector<string> &board){
    vector<string> tmp;
    tmp = board;
    bool flag = false;
    for(int i=0; i<board.size()-1; i++){
        for(int j=0; j<board[i].size()-1; j++){
            if(board[i][j]==' ') continue;
            if(board[i][j] == board[i][j+1]&&board[i][j] == board[i+1][j+1]&&board[i][j] == board[i+1][j]){
                tmp[i][j] = ' ';
                tmp[i][j+1] = ' ';
                tmp[i+1][j] = ' ';
                tmp[i+1][j+1] = ' ';
                flag = true;
            }
        }
    }
    board = tmp;
    return flag;
}
void down(vector<string> &board){
    for(int i=0; i<board[0].size(); i++){
        int now = board.size()-1;
        for(int j=board.size()-1; j>=0; j--){
            if(board[j][i] != ' '){
                char tmp = board[j][i];
                board[j][i] = ' ';
                board[now][i] = tmp;
                now--;
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(find(board)){
        down(board);
        
    }
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]==' '){
                answer++;
            }
        }
    }
    return answer;
}