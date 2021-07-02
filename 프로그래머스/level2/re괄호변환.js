const divide = (str) => {
    if(str === "")  return "";
    let cnt = 0;
    let flag = 0;
    let idx = -1;
    for(let i=0; i<str.length; i++){
        if(str[i] === '(')  cnt++;
        else                cnt--;
        if(cnt<0)           flag = 1;
        if(cnt === 0){
            idx = i+1;
            break;
        }
    }
    let u = str.substr(0, idx);
    let v = str.substr(idx);
    if(flag === 0){
        return u+divide(v);
    }
    else{
        let New = "(";
        New += divide(v) + ")";
        for(let i=1; i<u.length-1; i++){
            if(u[i] === ')')    New += "(";
            else                New += ")";
        }
        return New;
    }
};

function solution(p) {
    var answer = '';
    answer = divide(p);
    return answer;
}