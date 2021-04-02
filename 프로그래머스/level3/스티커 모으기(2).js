function solution(sticker) {
    var answer = 0;
    if(sticker.length===1)  return sticker[0];
    let dp1 = sticker.slice().fill(0);
    let dp2 = sticker.slice().fill(0);
    dp1[0] = sticker[0];
    dp1[1] = Math.max(sticker[1], sticker[0]);
    for(let i=2; i<sticker.length; i++){
        dp1[i] = Math.max(dp1[i-1], dp1[i-2] + sticker[i]);
    }
    dp2[1] = sticker[1];
    for(let i=2; i<sticker.length; i++){
        dp2[i] = Math.max(dp2[i-1], dp2[i-2] + sticker[i]);
    }
    answer = Math.max(dp1[sticker.length-2], dp2[sticker.length-1])
    return answer;
}