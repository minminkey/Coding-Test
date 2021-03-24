function fragment(str){
    let freg = [];
    for(let i=0; i<str.length-1; i++){
        if(str[i]>='A'&&str[i]<='Z'&&str[i+1]>='A'&&str[i+1]<='Z'){
            let tmp = str[i]+str[i+1];
            freg.push(tmp);
        }
    }
    return freg
}

function solution(str1, str2) {
    var answer = 0;
    str1 = str1.toUpperCase();
    str2 = str2.toUpperCase();
    let freg1 = fragment(str1).sort();
    let freg2 = fragment(str2).sort();
    let set = new Set([...freg1, ...freg2]);
    let union = 0;
    let inter = 0;
    set.forEach(x=>{
        let t1 = freg1.filter(a=>a===x).length;
        let t2 = freg2.filter(a=>a===x).length;
        union += Math.max(t1, t2);
        inter += Math.min(t1, t2);
    })
    if(union === 0){
        answer = 1;
    }
    else{
        answer = inter/union;
    }
    answer = Math.floor(answer*65536);
    return answer;
}