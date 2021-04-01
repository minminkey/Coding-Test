const dr = [-1, 0, 1, 0];
const dc = [0, 1, 0, -1];
let ans = 0x3f3f3f3f;

const go = (board, r, c, d) => {
    let nr = r;
    let nc = c;
    for(let i=0; i<4; i++){
        nr = nr + dr[d];
        nc = nc + dc[d];
        if(nr<0||nc<0||nr>=4||nc>=4){
            nr -= dr[d];
            nc -= dc[d];
            break;
        }
        if(board[nr][nc]!==0)   break;
    }
    return [nr, nc];
}

const findCard = (board, r, c, target) => {
    let visit = Array.from(Array(5), ()=> new Array(5).fill(0));
    visit[r][c] = 1;
    let q = [[r,c,0]];
    while(q.length!==0){
        let nowR = q[0][0];
        let nowC = q[0][1];
        let cnt = q[0][2];
        if(board[nowR][nowC]===target){
            board[nowR][nowC] = 0;
            return [nowR, nowC, cnt];
        }
        q.shift();
        for(let i=0; i<4; i++){
            let now = go(board, nowR, nowC, i);
            if(visit[now[0]][now[1]]===1)   continue;
            visit[now[0]][now[1]] = 1;
            q.push([now[0], now[1], cnt+1]);
        }
        for(let i=0; i<4; i++){
            let nr = nowR+dr[i];
            let nc = nowC+dc[i];
            if(nr<0||nc<0||nr>=4||nc>=4||visit[nr][nc]===1) continue;
            visit[nr][nc] = 1;
            q.push([nr, nc, cnt+1]);
        }
    }
}

const findAll = (board, sr, sc, ck, cnt) => {
    let flag = 0;
    for(let i=1; i<=6; i++){
        if(ck[i]===1)   flag = 1;
    }
    if(flag === 0){
        ans = Math.min(ans, cnt);
    }
    for(let i=1; i<=6; i++){
        if(ck[i]===0)   continue;
        let nowCk = ck.slice();
        nowCk[i] = 0;
        let nowBoard = [];
        for(let i=0; i<4; i++){
            nowBoard.push(board[i].slice());
        }
        let fstep = findCard(nowBoard, sr, sc, i);
        let sstep = findCard(nowBoard, fstep[0], fstep[1], i);
        let nowCnt = cnt + fstep[2] + sstep[2]+2;
        findAll(nowBoard, sstep[0], sstep[1], nowCk, nowCnt);
    }
}

function solution(board, r, c) {
    var answer = 0;
    let ck = new Array(7).fill(0);
    for(let i=0; i<4; i++){
        for(let j=0; j<4; j++){
            if(board[i][j]!==0&&ck[board[i][j]]===0)    ck[board[i][j]]++;
        }
    }
    findAll(board, r, c, ck, 0);
    answer = ans;
    return answer;
}