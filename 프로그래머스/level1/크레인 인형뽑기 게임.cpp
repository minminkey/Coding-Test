#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int R;

int pick(vector<vector<int>> &board, int c){
    for(int r=0; r<R; r++){
        if(board[r][c]!=0){
            int ans = board[r][c];
            board[r][c] = 0;
            return ans;
        }
    }
    return -1;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    R = board.size();
    stack<int> st;
    for(int i=0; i<moves.size(); i++){
        int result = pick(board, moves[i]-1);
        if(result==-1)  continue;
        if(!st.empty()&&st.top()==result){
            st.pop();
            answer += 2;
        }
        else{
            st.push(result);
        }
    }
    return answer;
}