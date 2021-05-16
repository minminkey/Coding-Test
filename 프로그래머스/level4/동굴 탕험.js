function solution(n, path, order) {
    var answer = true;
    let after = [];
    let want = [];
    let visit = [];
    let edge = [];
    let can = [];
    for(let i=0; i<n; i++){
        after.push([]);
        edge.push([]);
        want.push(0);
        visit.push(0);
        can.push(0);
    }
    path.forEach(p=>{
        edge[p[0]].push(p[1]);
        edge[p[1]].push(p[0]);
    });
    order.forEach(o=>{
        want[o[1]]++;
        after[o[0]].push(o[1]);
    });
    if(want[0]!==0) return false;
    let q = [0];
    visit[0] = 1;
    let cnt = 0;
    while(q.length>0){
        let si = q.length;
        for(let i=0; i<si; i++){
            let now = q[0];
            q.shift();
            cnt++;
            for(let j=0; j<after[now].length; j++){
                let next = after[now][j];
                want[next]--;
                if(want[next]<=0){
                    if(can[next]===1)   q.push(next);
                }
            }
            for(let j=0; j<edge[now].length; j++){
                if(visit[edge[now][j]]===0){
                    visit[edge[now][j]] = 1;
                    if(want[edge[now][j]]>0){
                        can[edge[now][j]] = 1;
                        continue;
                    }
                    q.push(edge[now][j]);
                }
            }
        }
    }
    if(cnt<n)  answer = false;
    return answer;
}