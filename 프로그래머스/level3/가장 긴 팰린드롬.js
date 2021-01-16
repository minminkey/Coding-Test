function count(idx, j, s){
    let cnt = 0;
    while(1){
        if(idx<0||j>=s.length)      break;
        if(s[idx]===s[j]){
            cnt += 2;
            idx--;
            j++;
        }
        else    break;
    }
    return cnt;
}
function solution(s)
{
    var answer = 0;
    for(let i=0; i<s.length; i++){
        let cnt = count(i-1, i+1, s)+1;
        let cnt1 = count(i, i+1, s);
        let cnt2 = count(i-1, i, s);
        answer = Math.max(answer, Math.max(cnt, Math.max(cnt1, cnt2)));
    }
    return answer;
}