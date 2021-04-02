const dr = [-1, 0, 1, 0];
const dc = [0, 1, 0, -1];

function solution(maps) {
    var answer = 9999999;
    let queue = [];
    const n = maps.length;
    const m = maps[0].length;
    let visit = [];
    for(let i=0; i<100; i++){
        visit.push(new Array(100).fill(0));
    }
    queue.push([0, 0, 1]);
    while(queue.length!==0){
        let nowR = queue[0][0];
        let nowC = queue[0][1];
        let cnt = queue[0][2];
        queue.shift();
        if(nowR===n-1&&nowC===m-1){
            answer = Math.min(answer, cnt);
        }
        for(let i=0; i<4; i++){
            let nr = nowR + dr[i];
            let nc = nowC + dc[i];
            if(nr<0||nc<0||nr>=n||nc>=m) continue;
            if(visit[nr][nc]===1||maps[nr][nc]===0) continue;
            visit[nr][nc] = 1;
            queue.push([nr, nc, cnt+1]);
        }
    }
    if(answer === 9999999)  answer = -1;
    return answer;
}