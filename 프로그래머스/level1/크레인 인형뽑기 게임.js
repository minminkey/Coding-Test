const pick = (board, col) => {
    for(let i=0; i<board.length; i++){
        if(board[i][col]!==0){
            let now = board[i][col];
            board[i][col] = 0;
            return now;
        }
    }
    return -1;
}

function solution(board, moves) {
    var answer = 0;
    let st = [];
    moves.forEach(move => {
        let now = pick(board, move-1);
        if(now!==-1){
            if(st[st.length-1]===now){
                answer += 2;
                st.pop();
            }
            else{
                st.push(now);
            }
        }
    });
    return answer;
}