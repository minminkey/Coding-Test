function solution(n, computers) {
    let answer = 0;
    let visit = Array(n).fill(0);
    let queue = [];
    
    for(let i=0; i<n; i++){
        if(visit[i]===1)    continue;
        visit[i] = 1;
        answer++;
        for(let j=0; j<n; j++){
            if(computers[i][j]===0||visit[j]===1)    continue;
            visit[j] = 1;
            queue.push(j);
        }
        while(queue.length !== 0){
            let now = queue[0];
            queue.shift();
            for(let j=0; j<n; j++){
                if(computers[now][j]===0||visit[j]===1)  continue;
                visit[j] = 1;
                queue.push(j);
            }
        }
    }
    return answer;
}