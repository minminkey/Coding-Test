const getPermutations= function (arr, selectNumber) {
    const results = [];
    if (selectNumber === 1) return arr.map((value) => [value]);

    arr.forEach((fixed, index, origin) => {
        const rest = [...origin.slice(0, index), ...origin.slice(index+1)];
        const permutations = getPermutations(rest, selectNumber - 1);
        const attached = permutations.map((permutation) => [fixed, ...permutation]);
        results.push(...attached);
    });
    return results;
};

function solution(n, weak, Dist) {
    var answer = 100;
    Dist.sort((a, b)=>b-a);
    let per = getPermutations(Dist, Dist.length);
    for(let k=0; k<weak.length; k++){
        // console.log(weak);
        per.forEach(dist=>{
            let idx = 0;
            let cnt = 0;
            // console.log(dist);
            for(let i=0; i<dist.length; i++){
                let now = weak[idx];
                let next = weak[idx]+dist[i];
                if(next>=n){
                    while(weak[idx]>=now||weak[idx]<=next%n){
                        idx++;
                    }
                }
                else{
                    while(weak[idx]>=now&&weak[idx]<=next){
                        idx++;
                    }
                }
                cnt++;
                // console.log(now, next, idx, cnt);
                if(idx>=weak.length){
                    answer = Math.min(answer, cnt);
                    break;
                }
            }
        })
        weak.push(weak[0]);
        weak.shift();
    }
    if(answer === 100)  answer = -1;
    return answer;
}