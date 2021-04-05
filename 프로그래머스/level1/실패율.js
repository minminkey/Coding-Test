function solution(N, stages) {
    var answer = [];
    let stage = new Array(N+2).fill(0);
    let dp = new Array(N+2).fill(0);
    stage[0] = stages.length;
    stages.forEach(st => {
        dp[st]--;
    });
    for(let i=1; i<=N; i++){
        stage[i] = stage[i-1] + dp[i];
    }
    let ans = [];
    for(let i=1; i<=N; i++){
        if(stage[i-1]===0){
            for(let j=i; j<=N; j++){
                ans.push([0,j]);
            }
            break;
        }
        ans.push([-1*dp[i]/stage[i-1], i]);
    }
    ans.sort((a,b)=>{
        if(a[0]===b[0])  return a[1]-b[1];
        return b[0]-a[0];
    });
    ans.forEach(a=>answer.push(a[1]));
    return answer;
}