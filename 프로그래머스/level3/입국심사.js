function solution(n, times) {
    var answer = 0;
    times.sort((a,b)=>a-b);
    let low = 1;
    let high = times[times.length-1]*n;
    while(low<=high){
        let mid = Math.floor((low+high)/2);
        let cnt = 0;
        for(let i=0; i<times.length; i++){
            cnt += Math.floor(mid/times[i]);
        }
        if(cnt<n){
            low = mid + 1;
        }
        else{
            if(mid<=high)   answer = mid;
            high = mid-1;
        }
    }
    return answer;
}