const spin = (arr) => {
    let output = [];
    for(let i=0; i<arr[0].length; i++){
        let tmp = [];
        for(let j=arr.length-1; j>=0; j--){
            tmp.push(arr[j][i]);
        }
        output.push(tmp);
    }
    return output;
}

const ck = (board, m, n) => {
    for(let i=m-1; i<m+n-1; i++){
        for(let j=m-1; j<m+n-1; j++){
            if(board[i][j]===0) return false;
        }
    }
    return true;
}

const go = (key, lock) => {
    let m = key.length;
    let n = lock.length;
    let board = [];
    for(let i=0; i<2*m+n-2; i++){
        board.push(new Array(2*m+n-2).fill(0));
    }
    for(let r=0; r<n; r++){
        for(let c=0; c<n; c++){
            board[m+r-1][m+c-1] = lock[r][c];
        }
    }
    for(let r=0; r<m+n-1; r++){
        for(let c=0; c<m+n-1; c++){
            let newBoard = [];
            for(let i=0; i<board.length; i++){
                newBoard.push(board[i].slice());
            }
            for(let i=0; i<m; i++){
                for(let j=0; j<m; j++){
                    if(key[i][j]===1){
                        if(newBoard[r+i][c+j]===1)  newBoard[r+i][c+j] = 0;
                        else                        newBoard[r+i][c+j] = 1;
                        
                    }
                }
            }
            if(ck(newBoard, m, n)){
                return true;
            }
        }
    }
    return false;
}

function solution(key, lock) {
    var answer = false;
    for(let i=0; i<4; i++){
        if(go(key, lock)){
            return true;
        }
        key = spin(key)
    }
    return answer;
}