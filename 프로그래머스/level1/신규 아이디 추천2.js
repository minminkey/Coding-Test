const trans = (str) => {
    str = str.toLowerCase();
    let ans = [];
    for(let i=0; i<str.length; i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='0'&&str[i]<='9')||str[i]==='-'||str[i]==='_'||str[i]==='.'){
            if(str[i] === '.'&&ans[ans.length-1] === '.')   continue;
            ans.push(str[i]);
        }
    }
    if(ans[0] === '.')  ans.shift();
    if(ans[ans.length-1] === '.')   ans.pop();
    let s = ans.join("")
    if(s.length === 0)  s = "a";
    if(s.length >= 16){
        if(s[14] === '.'){
            s = s.substr(0, 14);
        }
        else{
            s = s.substr(0, 15);
        }
    }
    else if(s.length<=2){
        while(s.length!=3){
            s += s[s.length-1];
        }
    }
    return s;
}

function solution(new_id) {
    var answer = '';
    answer = trans(new_id);
    return answer;
}