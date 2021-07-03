const getTime = (str) => {
    let arr = str.split(":").map(s=>Number(s));
    return arr[0]*3600+arr[1]*60+arr[2];
}

function solution(play_time, adv_time, logs) {
    var answer = '';
    let play = getTime(play_time);
    let adv = getTime(adv_time);
    let log = [];
    let times = new Array(play).fill(0);
    logs = logs.map(log=>log.split("-").map(str=>getTime(str)));
    logs.forEach(log=>{
        times[log[0]]++;
        times[log[1]]--;
    });
    for(let i=1; i<=play; i++){
        times[i] += times[i-1];
    }
    let s = 0;
    let e = 0;
    let sum = 0;
    let ans = 0;
    for(e=0; e<adv; e++){
        sum += times[e];
    }
    let Max = sum;
    for(e=adv; e<=play; e++){
        sum += times[e];
        sum -= times[s];
        s++;
        if(sum>Max){
            ans = s;
            Max = sum;
        }
    }
    let hms =[String(Math.floor(ans/3600)), String(Math.floor((ans%3600)/60)), String((ans%3600)%60)]
    hms = hms.map(a=>{
        if(a.length === 1)  return "0"+a;
        else                return a;
    });
    answer = hms[0] + ":" + hms[1] + ":" + hms[2];
    return answer;
}