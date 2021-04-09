function solution(msg) {
    var answer = [];
    let dic = {};
    for(let i=1; i<=26; i++){
        dic[String.fromCharCode(65+i-1)] = i;
    }
    let idx = 27;
    for(let i=0; i<msg.length; i++){
        let word = "";
        let n = i;
        while(dic[word+msg[n]]!==undefined){
            word += msg[n++];
        }
        answer.push(dic[word]);
        dic[word+msg[n]] = idx++;
        i = n-1;
    }
    return answer;
}