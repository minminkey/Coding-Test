function solution(n, record) {
    var answer = [];
    let server = [];
    for(let i=0; i<n; i++){
        let tmp = [];
        server.push(tmp);
    }
    for(let i=0; i<record.length; i++){
        let str = record[i].split(' ');
        let now = parseInt(str[0])-1;
        let flag = 0;
        for(let j=0; j<server[now].length; j++){
            if(server[now][j]===str[1]){
                flag = 1;
                break;
            }
        }
        if(flag===1)    continue;
        if(server[now].length===5)  server[now].shift();
        server[now].push(str[1]);
    }
    for(let i=0; i<n; i++){
        for(let j=0; j<server[i].length; j++){
            answer.push(server[i][j]);
        }
    }
    return answer;
}