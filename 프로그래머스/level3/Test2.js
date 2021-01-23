function solution(m, v) {
    var answer = 0;
    let now = 0;
    let board = new Array(100001).fill(m);
    for(let i=0; i<v.length; i++){
        let deep;
        for(deep=now; deep>=0; deep--){
               if(board[deep]<v[i])     break;
        }
        if(now===deep)  now++;
        board[deep+1] -= v[i];
    }
    answer = now+1;
    return answer;
}