const ck = (str, len) => {
    let res = "";
    for(let s=0; s<str.length; s+=len){
        let cnt = 0;
        let ind = str.substr(s,len);
        for(let now=s; now<str.length; now += len){
            if(ind === str.substr(now,len))   cnt++;
            else                            break;
        }
        if(cnt>1){
            res += String(cnt) + ind;
            s += (cnt-1)*len;
        }
        else{
            res += ind;
        }
    }
    return res.length
};

function solution(s) {
    var answer = 1000;
    for(let i=1; i<=s.length; i++){
        answer = Math.min(answer, ck(s, i));
    }
    return answer;
}