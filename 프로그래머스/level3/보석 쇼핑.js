function solution(gems) {
    var answer = [];
    let obj = {};
    let cnt = 0;
    gems.forEach(gem=>{
        if(obj[gem]===undefined){
            cnt++;
            obj[gem] = 0;
        }
    });
    let queue = [];
    let ncnt = 0;
    let l = 0;
    let s = 0;
    let e = gems.length;
    for(let r=0; r<gems.length; r++){
        let now = gems[r];
        queue.push(now);
        if(obj[now]===0){
            ncnt++;
        }
        obj[now]++;
        while(ncnt===cnt){
            let out = queue[0];
            if(obj[out]>=2){
                obj[out]--;
                l++;
                queue.shift();
            }
            else    break;
        }
        if(ncnt===cnt){
            if(e-s>r-l){
                s = l;
                e = r;
            }
        }
    }
    answer = [s+1, e+1];
    return answer;
}