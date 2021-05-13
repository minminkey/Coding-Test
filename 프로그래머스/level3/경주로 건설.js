let dr = [-1, 0, 1, 0];
let dc = [0, 1, 0, -1];

function solution(board) {
    var answer = 0;
    let visit = [];
    let N = board.length;
    for(let i=0; i<board.length; i++){
        let tmp = new Array(board[i].length).fill(987654321);
        visit.push(tmp);
    }
    let q = [];
    q.push([0, 0, -1, 0]);
    visit[0][0] = 0;
    while(q.length>0){
        let r = q[0][0];
        let c = q[0][1];
        let di = q[0][2];
        let cost = q[0][3];
        q.shift();
        for(let d=0; d<4; d++){
            if(di!==-1&&d===(di+2)%4)    continue;
            let nr = r + dr[d];
            let nc = c + dc[d];
            let ncost = cost + 100;
            if(di!==-1&&d!==di)  ncost += 500;
            if(nr<0||nc<0||nr>=N||nc>=N||board[nr][nc]===1)    continue;
            if(visit[nr][nc]<ncost)         continue;
            visit[nr][nc] = ncost;
            q.push([nr, nc, d, ncost]);
        }
    }
    answer = visit[N-1][N-1];
    return answer;
}