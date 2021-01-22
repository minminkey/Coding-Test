function solution(a) {
    var answer = -1;
    let size = a.length;
    let visit = new Array(size+1).fill(0);
    let cnt = new Array(size+1).fill(0)
    a.map(x=>cnt[x]++);
    for(let i=0; i<size; i++){
        let t = a[i];
        let ans = 0;
        if(visit[t]===1)    continue;
        if(answer>cnt[t])   continue;
        visit[t] = 1;
        for(let j = i-1; j<size-1; j++){
            if(j<0) j=0;
            if(a[j]!==t&&a[j+1]!==t)  continue;
            if(a[j]===a[j+1])         continue;
            ans++;
            j++;
        }
        answer = Math.max(answer, ans);
    }
    if(size===1)    answer = 0;
    return answer*2;
}