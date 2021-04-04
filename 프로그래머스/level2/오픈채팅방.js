let user = {};
let ans = [];

const enter = (id, nick) => {
    user[id] = nick;
    ans.push([1, id]);
}

const leave = (id) => {
    ans.push([2, id]);
}

const change = (id, nick) => {
    user[id] = nick;
}

const order = (str) => {
    let info = str.split(' ');
    if(info[0]==='Enter'){
        enter(info[1], info[2]);
    }
    else if(info[0]==='Leave'){
        leave(info[1]);
    }
    else{
        change(info[1], info[2]);
    }
}

function solution(record) {
    var answer = [];
    record.forEach(r=>order(r));
    ans.forEach(a=>{
        if(a[0]===1){
           answer.push(`${user[a[1]]}님이 들어왔습니다.`);
        }
        else{
            answer.push(`${user[a[1]]}님이 나갔습니다.`);
        }
    });
    return answer;
}