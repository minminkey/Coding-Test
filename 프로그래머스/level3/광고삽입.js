const getTime = (str)=>{
    let times = str.split(":");
    times = times.map(t=>Number(t));
    return times[0]*3600 + times[1]*60 + times[2];
}

function solution(play_time, adv_time, logs) {
    var answer = '';
    let ptime = getTime(play_time);
    let dp = new Array(400000).fill(0);
    let atime = getTime(adv_time);
    logs.forEach(log=>{
        let str = log.split("-");
        let tmp = [];
        str.forEach(s=>tmp.push(getTime(s)));
        dp[tmp[0]]++;
        dp[tmp[1]]--;
    });
    for(let i=1; i<=ptime; i++){
        dp[i] = dp[i-1] + dp[i];
    }
    let now = dp.slice(0,atime).reduce((a,b)=>a+b);
    let maxNow = now;
    let idx = 0;
    let ans = 0;
    for(let i=atime; i<ptime; i++, idx++){
        now = now - dp[idx] + dp[i];
        if(now>maxNow){
            maxNow = now;
            ans = idx+1;
        }
    }
    const f = v => `${Math.floor(v)}`.padStart(2, 0);
    answer = `${f(ans/3600)}:${f(ans%3600/60)}:${f(ans%60)}`;
    return answer;
}