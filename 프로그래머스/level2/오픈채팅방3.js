function solution(record) {
    var answer = [];
    let list = [];
    let user = {};
    record.forEach(str => {
        let info = str.split(' ');
        let id = info[1];
        let nick = info[2];
        if(info[0] === "Enter"){
            user[id] = nick;
            list.push([id, 0]);
        }
        else if(info[0] === "Leave"){
            list.push([id, 1]);
        }
        else{
            user[id] = nick;
        }
    });
    list.forEach(info => {
        let str = user[info[0]];
        if(info[1] === 0)   str += "님이 들어왔습니다.";
        else                str += "님이 나갔습니다.";
        answer.push(str);
    });
    return answer;
}