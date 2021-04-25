function solution(genres, plays) {
    var answer = [];
    let obj = {};
    let visit = {};
    let ans = [];
    for(let i=0; i<plays.length; i++){
        let g = genres[i];
        let cnt = plays[i];
        if(obj[g]===undefined){
            obj[g] = cnt;
            visit[g] = 0;
        }
        else{
            obj[g] += cnt;
        }
        ans.push([g, cnt, i]);
    }
    ans.sort((a,b)=>{
        if(obj[a[0]]===obj[b[0]]){
            if(a[1]===b[1]){
                return a[2] - b[2];
            }
            return b[1] - a[1];
        }
        return obj[b[0]] - obj[a[0]];
    })
    // console.log(ans);
    for(let i=0; i<ans.length; i++){
        if(visit[ans[i][0]]>=2)    continue;
        answer.push(ans[i][2]);
        visit[ans[i][0]]++;
    }
    return answer;
}