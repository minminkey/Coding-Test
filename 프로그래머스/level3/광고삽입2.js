const getTime = (str) => {
    let arr = str.split(':').map(s=>Number(s));
    return arr[0]*3600 + arr[1]*60 + arr[2];
}

function solution(play_time, adv_time, logs) {
    var answer = '';
    let play = getTime(play_time);
    let adv = getTime(adv_time);
    let view = new Array(play+10).fill(0);
    logs.forEach(str => {
        let arr = str.split("-");
        view[getTime(arr[0])]++;
        view[getTime(arr[1])]--;
    });
    for(let i=1; i<=play; i++){
        view[i] += view[i-1];
    }
    let sum = 0;
    for(let i=0; i<adv; i++){
        sum += view[i];
    }
    let st = 0;
    let ans = 0;
    let maxSum = sum;
    for(let i=adv; i<=play; i++){
        sum += view[i];
        sum -= view[st++];
        if(maxSum < sum){
            maxSum = sum;
            ans = st;
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