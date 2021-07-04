function solution(k, rates) {
    var answer = 0;
    let cnt = 0;
    let now = k;
    for(let i=0; i<rates.length-1; i++){
        if(cnt === 0 && now >= rates[i]){
            if(rates[i]<rates[i+1]){
                cnt++;
                now -= rates[i];
            }
        }
        else if(cnt === 1){
            if(rates[i]>rates[i+1]){
                cnt--;
                now += rates[i];
            }
        }
    }
    if(cnt === 1)    now += rates[rates.length-1];
    return now;
}