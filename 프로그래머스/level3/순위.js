let win = [];
let lose = [];
let res = [];

let pre = (now, visit) => {
    let sum = 0;
    if(win[now].length==0){
        return sum+1;
    }
    for(let i=0; i<win[now].length; i++){
        if(visit[win[now][i]]===1)    continue;
        visit[win[now][i]] = 1;
        sum += pre(win[now][i], visit);
    }
    return sum+1;
}

let post = (now, visit) => {
    let sum = 0;
    if(lose[now].length==0){
        return sum+1;
    }
    for(let i=0; i<lose[now].length; i++){
        if(visit[lose[now][i]]===1) continue;
        visit[lose[now][i]] = 1;
        sum += post(lose[now][i], visit);
    }
    return sum+1;
    
}

function solution(n, results) {
    for(let i=0; i<=100; i++){
        win.push([]);
        lose.push([]);
        res.push([-1, -1]);
    }
    results.forEach(result => {
        let w = result[0];
        let l = result[1];
        win[l].push(w);
        lose[w].push(l);
    });
    var answer = 0;
    for(let i=1; i<=n; i++){
        let visit = new Array(100).fill(0);
        if(res[i][0]==-1)   res[i][0] = pre(i, visit)-1;
        visit.forEach(x => x=0);
        if(res[i][1]==-1)   res[i][1] = post(i, visit)-1;
        if(res[i][0]+res[i][1]===n-1)   answer++;
    }
    return answer;
}