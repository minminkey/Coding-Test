function solution(bl, weight, tw) {
    var answer = 0;
    let sum = 0;
    let idx = 0;
    let cnt = 0;
    let on = [];
    while(1){
        answer++;
        if(on.length!=0&&answer-on[0][0]>=bl){
            cnt++;
            if(cnt==tw.length)  break;
            sum -= on[0][1];
            on.shift();
        }
        if(sum+tw[idx]<=weight){
            sum += tw[idx];
            on.push([answer, tw[idx]]);
            idx++;
        }
    }
    return answer;
}