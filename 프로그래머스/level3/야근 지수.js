function solution(n, works) {
    var answer = 0;
    for(let i=0; i<n; i++){
        works.sort((a,b)=>b-a);
        if(works[0]==0) continue;
        for(let j=1; j<works.length; j++){
            if(works[j]!==works[0]||i+1>=n) break;
            works[j]--;
            i++;
        }
        works[0]--;
    }
    for(let i=0; i<works.length; i++){
        answer += works[i]*works[i];
    }
    return answer;
}