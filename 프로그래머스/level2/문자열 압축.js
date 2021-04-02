function solution(s) {
    var answer = 1001;
    if(s.length===1)    return 1;
    for(let i=1; i<=Math.floor(s.length/2); i++){
        let str = "";
        for(let j=0; j<s.length; j++){
            let now = s.substr(j, i);
            let num = 0;
            while(s.length>=j+i+num*i&&now === s.substr(j+i+num*i, i)){
                num++;
            }
            if(num>0){
                str += String(num+1) + now;
            }
            else{
                str += now;
            }
            j += i*(num+1) - 1;
        }
        answer = Math.min(answer, str.length);
    }
    return answer;
}