function solution(n, s) {
    var answer = [];
    if(n>s) return [-1];
    let div = Math.floor(s/n);
    let diff = s%n;
    for(let i=0; i<n; i++){
        answer.push(div);
    }
    let tmp = n-1;
    for(let i=0; i<diff; i++){
        answer[tmp--]++;
    }
    return answer;
}