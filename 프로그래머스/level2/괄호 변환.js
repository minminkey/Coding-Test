const findIdx = (str) => {
    let flag = 0;
    let now = 0;
    for(let i=0; i<str.length; i++){
        if(str[i]==='(')    now++;
        else if(str[i]===')')   now--;
        if(now<0)    flag = 1;
        if(i!==0&&now===0)    return [i, flag];
    }
}

const divide = (str) => {
    let info = findIdx(str);
    let u = str.slice(0, info[0]+1);
    let v = str.slice(info[0]+1);
    return [u, v, info[1]];
}

const go = (str) => {
    let ans = "";
    if(str.length===0)  return "";
    let result = divide(str);
    if(result[2]===0){
        ans = result[0] + (result[1]);
        ans = result[0] + go(result[1]);
        return ans;
    }
    let now = "(" + go(result[1]) + ")";
    result[0] = result[0].slice(1, -1).split("").map(f=>f==="(" ? ")" : "(").join("");
    ans = now + result[0];
    return ans;
}

function solution(p) {
    var answer = '';
    answer = go(p);
    // p[0] = '1';
    return answer;
}