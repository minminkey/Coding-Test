let edge = [];
let visit;
let dp;
let pass;

const dfs = (s, cnt) => {
    dp[s] = cnt;
    for(let i=0; i<edge[s].length; i++){
        let next = edge[s][i];
        if(visit[next]===1) continue;
        visit[next] = 1;
        dfs(next, cnt+pass[next]);
    }
}

function solution(n, passenger, train) {
    var answer = [0, 0];
    passenger.unshift(0);
    pass = passenger.slice();
    dp = new Array(n+1).fill(0);
    visit = new Array(n+1).fill(0);
    for(let i=0; i<=n; i++){
        edge.push([]);
    }
    train.forEach(t=>{
        edge[t[0]].push(t[1]);
        edge[t[1]].push(t[0]);
    });
    visit[1] = 1;
    dfs(1, pass[1]);
    for(let i=n; i>0; i--){
        if(answer[1]<dp[i]){
            answer = [i, dp[i]];
        }
    }
    return answer;
}