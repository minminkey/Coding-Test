//String
function solution(s) {
    var answer = "";
    let info = {"zero":0, "one":1, "two":2, "three":3, "four":4, "five":5, "six":6, "seven":7, "eight":8, "nine":9};
    let word = "";
    for(let i=0; i<s.length; i++){
        if(s[i]>='0'&&s[i]<='9'){
            answer += s[i];
            continue;
        }
        word += s[i];
        if(info[word] !== undefined){
            answer += info[word];
            word = "";
        }
    }
    answer = Number(answer);
    return answer;
}