function solution(pr, location) {
    var answer = 1;
    let idx = 0;
    let list = pr.map(a=>[a, idx++]);
    pr.sort((a,b)=>b-a);
    while(1){
        if(list[0][0] === pr[0]){
            if(list[0][1]===location)   break;
            pr.shift();
            list.shift();
            answer++;
        }
        else{
            let tmp = list[0];
            list.shift();
            list.push(tmp);
        }
    }
    return answer;
}