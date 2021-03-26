function ck(board){
    let copy = [];
    for(let i=0; i<board.length; i++){
        copy.push(board[i].slice());
    }
    let f = false;
    for(let i=0; i<board.length-1; i++){
        for(let j=0; j<board[i].length-1; j++){
            if(board[i][j] === ' ') continue;
            if(board[i][j]===board[i][j+1]&&board[i][j]===board[i+1][j]&&board[i][j]===board[i+1][j+1]){
                copy[i][j] = ' ';
                copy[i+1][j] = ' ';
                copy[i][j+1] = ' ';
                copy[i+1][j+1] = ' ';
                f = true;
            }
        }
    }
    for(let i=0; i<copy.length; i++){
        board[i] = copy[i].slice();
    }
    return f;
}
function down(board){
    for(let c=0; c<board[0].length; c++){
        let now = board.length-1;
        for(let r=board.length-1; r>=0; r--){
            if(board[r][c]===' '){
                
            }
            else{
                let tmp = board[r][c];
                board[r][c] = ' ';
                board[now][c] = tmp;
                now--;
            }
        }
    }
}
function solution(m, n, board) {
    var answer = 0;
    board = board.map(s=>s.split(''));
    while(ck(board)){
        down(board);
    }
    for(let i=0; i<board.length; i++){
        for(let j=0; j<board[i].length; j++){
            if(board[i][j]===' ')   answer++;
        }
    }
    return answer;
}