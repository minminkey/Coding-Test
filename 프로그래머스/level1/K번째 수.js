function solution(array, commands) {
    var answer = [];
    commands.forEach(com => {
        let tmp = array.slice(com[0]-1, com[1]).sort((a,b) => a-b);
        answer.push(tmp[com[2]-1]);
    })
    return answer;
}