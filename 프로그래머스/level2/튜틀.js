function solution(s) {
    var answer = [];
    let sub = s.slice(2,-2).split("},{").map(now=>now.split(','));
    let obj = {};
    sub.forEach(now=>{
        now.forEach(k=>{
            if(obj[k]===undefined){
                answer.push(k);
                obj[k] = 0;
            }
            obj[k]++;
        });
    });
    answer = answer.sort((a,b)=>obj[b]-obj[a]).map(ans=>Number(ans));
    return answer;
}