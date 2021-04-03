let robot = [];

const findarr = (visit, now, r, s) => {
    if(now.length===r){
        robot.push(now.slice());
    }
    for(let i=s; i<visit.length; i++){
        if(visit[i]===1)    continue;
        let realnow = now.slice();
        let realvisit = visit.slice();
        realvisit[i] = 1;
        realnow.push(i);
        findarr(realvisit, realnow, r, i+1);
    }
}

function solution(needs, r) {
    var answer = 0;
    let visit = new Array(15).fill(0);
    findarr(visit, [], r, 0);
    robot.forEach(ro=>{
        let cnt = needs.length;
        for(let i=0; i<needs.length; i++){
            let idx = 0;
            for(let j=0; j<needs[i].length; j++){
                if(needs[i][j]===1){
                    while(ro[idx]<j)    idx++;
                    if(ro[idx]===j) continue;
                    else{
                        cnt--;
                        break;
                    }
                }
            }
        }
        answer = Math.max(answer, cnt);
    });
    return answer;
}