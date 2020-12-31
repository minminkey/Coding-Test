#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    vector<vector<int>> squrboard;
    squrboard = board;
    for(int i=1; i<board.size(); i++){
        for(int j=1; j<board[i].size(); j++){
            if(squrboard[i][j]==1){
                squrboard[i][j] = min(squrboard[i-1][j-1], min(squrboard[i-1][j], squrboard[i][j-1])) + 1;
                answer = max(answer, squrboard[i][j]);
            }
        }
    }
    if(answer == 0){
        for(int i=0; i<board.size(); i++){
            if(board[i][0]==1)  return 1;
        }
        for(int i=0; i<board.size(); i++){
            if(board[0][i]==1)  return 1;
        }
    }
    return answer*answer;
}