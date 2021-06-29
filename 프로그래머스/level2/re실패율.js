function solution(N, stages) {
    var answer = [];
    let info = [];
    let clear = [];
    let fail = [];
    for(let i=0; i<=N+1; i++){
        info.push(0);
        clear.push(0);
        fail.push([]);
    }
    stages.forEach(stage=>info[stage]++);
    clear[0] = stages.length;
    for(let i=1; i<info.length; i++){
        clear[i] = clear[i-1] - info[i];
    }
    for(let i=1; i<clear.length-1; i++){
        fail[i] = [(clear[i-1]-clear[i])/clear[i], i];
    }
    fail.shift();
    fail.pop();
    fail.sort((a,b)=>{
        if(a[0]===b[0]) return a[1]-b[1];
        return b[0]-a[0];
    })
    answer = fail.map(f=>f[1])
    return answer;
}