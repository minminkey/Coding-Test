function solution(N, stages) {
    var answer = [];
    let tmp = new Array(N+2).fill(0);
    stages.forEach(n => {
        tmp[n]++;
    });
    let now = stages.length;
    let clear = new Array(N+2).fill(0);
    clear[0] = now;
    for(let i=1; i<=N+1; i++){
        clear[i] = clear[i-1] - tmp[i];
    }
    let rate = [];
    for(let i=1; i<=N; i++){
        if(clear[i-1]===0){
            rate.push([i, 0]);
        }
        else{
            rate.push([i, tmp[i]/clear[i-1]]);
        }
    }
    rate.sort((a,b)=>{
        if(a[1]===b[1]){
            return a[0] - b[0];
        }
        return b[1] - a[1];
    });
    answer = rate.map(z=>z[0]);
    return answer;
}