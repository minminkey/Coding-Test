function solution(stones, k) {
    var answer = 0;
    let left = 0;
    let right = 0;
    stones.map(x=>right = Math.max(right, x));
    while(left<=right){
        let mid = Math.floor((right+left)/2);
        let tmp = stones.map(x=>x-mid);
        let flag = 1;
        for(let i=0; i<stones.length; i++){
            if(tmp[i]<=0){
                let flag1 = 0;
                for(let j=i+1; j<=i+k-1; j++){
                    if(tmp[j]>0||j>=tmp.length){
                        flag1 = 1;
                        i=j;
                        break;
                    }
                }
                if(flag1===0){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag === 1){
            left = mid+1;
            answer = mid;
        }
        else{
            right = mid-1;
        }
    }    
    return answer+1;
}