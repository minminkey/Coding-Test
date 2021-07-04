const bk = [[[2],[2],[2]], [[2,2,2]], [[2, 0],[2,2]], [[0,2],[2,2]], [[2,2],[0,2]], [[2,2],[2,0]]];

const ck = (board) => {
    let l = board.length;
    // console.log(board);
    let cnt = 0;
    for(let r=0; r<l; r++){
        let flag = 0;
        for(let c=0; c<l; c++){
            if(board[r][c] === 0)   flag = 1;
        }
        if(flag === 0)  cnt++;
    }
    return cnt;
}

const down = (board) => {
    let l = board.length;
    // console.log(board);
    let Min = l;
    for(let c=0; c<l; c++){
        let flag = 0;
        let cnt = 0;
        for(let r=0; r<l; r++){
            if(board[r][c] === 2){
                flag = 1;
            }
            if(flag === 1){
                if(board[r][c] === 0)   cnt++;
                else if(board[r][c] === 1)  break;
            }
        }
        if(flag === 1){
            Min = Math.min(Min, cnt);
        }
    }
    for(let r=l-1; r>=0; r--){
        for(let c=0; c<l; c++){
            if(board[r][c] === 2){
                board[r][c] = 0;
                board[r+Min][c] = 2;
            }
        }
    }
    return ck(board);
}

const put = (idx, col, tboard) => {
    let board = [];
    for(let i=0; i<tboard.length; i++){
        let tmp = []
        for(let j=0; j<tboard.length; j++){
            tmp.push(tboard[i][j]);
        }
        board.push(tmp);
    }
    let y = bk[idx].length;
    let x = bk[idx][0].length;
    for(let r=0; r<y; r++){
        for(let c=0; c<x; c++){
            // console.log(r, c,col, board[r][c+col], bk[idx][r][c])
            if(bk[idx][r][c] === 2){
                if(board[r][c+col] === 1)   return 0;
                board[r][c+col] = 2;
            }
        }
    }
    return down(board);
}

function solution(block,board) {
    let answer = 0;
    // block = 4;
    let limit = board.length - bk[block][0].length;
    for(let col=0; col<=limit; col++){
        answer = Math.max(answer, put(block, col, board));
    }
    return answer;
}