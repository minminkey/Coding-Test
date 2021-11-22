function solution(cakes, cut_rows, cut_columns) {
    let dr = [-1, 0, 1, 0];
    let dc = [0, 1, 0, -1];
    var answer = 0;
    let N = cakes.length;
    let visit = [];
    for(let i=0; i<cakes.length; i++){
        let tmp = [];
        for(let j=0; j<cakes[i].length; j++){
            tmp.push(0);
        }
        visit.push(tmp);
    }
    let dir = [];
    for(let i=0; i<4; i++){
        dir.push({});
    }
    cut_rows.forEach(row => {
        dir[0][row-1] = 1;
        dir[2][row] = 1;
    })
    cut_columns.forEach(column => {
        dir[3][column-1] = 1;
        dir[1][column] = 1;
    })
    for(let i=0; i<cakes.length; i++){
        for(let j=0; j<cakes[i].length; j++){
            if(visit[i][j] === 1)   continue;
            visit[i][j] = 1;
            let q = [];
            let cnt = 1;
            let ck = {};
            ck[cakes[i][j]] = 1;
            q.push([i, j]);
            while(q.length>0){
                let r = q[0][0];
                let c = q[0][1];
                q.shift();
                for(let d=0; d<4; d++){
                    let nr = r + dr[d];
                    let nc = c + dc[d];
                    if(nr<0||nc<0||nr>=N||nc>=N)    continue;
                    if(d===0 || d===2){
                        if(dir[d][nr] !== undefined)    continue;
                    }
                    if(d===1 || d===3){
                        if(dir[d][nc] !== undefined)    continue;
                    }
                    if(visit[nr][nc] === 1) continue;
                    visit[nr][nc] = 1;
                    if(ck[cakes[nr][nc]] === undefined){
                        ck[cakes[nr][nc]] = 1;
                        cnt++;
                    }
                    q.push([nr, nc]);
                }
            }
            answer = Math.max(answer, cnt);
        }
    }
    return answer;
}