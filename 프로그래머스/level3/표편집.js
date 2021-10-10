//구현
let node = [];
let deleted = [];
let N;

const Move = (type, now, cnt) => {
    let next = now;
    if(type === 'U'){
        for(let i=0; i<cnt; i++){
            next = node[next].up;
        }
    }
    else{
        for(let i=0; i<cnt; i++){
            next = node[next].down;
        }
    }
    return next;
}

const Delete = (now) => {
    node[now].live = false;
    deleted.push(now);
    let up = node[now].up;
    let down = node[now].down;
    if(up !== -1){
        node[up].down = down;
    }
    if(down !== -1){
        node[down].up = up;
        return down;
    }
    return up;
}

const Recovery = () => {
    let last = deleted[deleted.length - 1];
    deleted.pop();
    node[last].live = true;
    let up = node[last].up;
    let down = node[last].down;
    if(up !== -1){
        node[up].down = last;
    }
    if(down !== -1){
        node[down].up = last;
    }
}

function solution(n, k, cmd) {
    var answer = "";
    N = n;
    let now = k;
    for(let i=0; i<N; i++){
        let info = {
            id: i,
            up: i-1,
            down: i+1,
            live: true
        };
        node.push(info);
    }
    node[N-1].down = -1;
    cmd.forEach(str => {
        let info = str.split(' ');
        if(info[0] === 'U' || info[0] === 'D'){
            let cnt = Number(info[1]);
            now = Move(info[0], now, cnt);
        }
        else if(info[0] === 'C'){
            now = Delete(now);
        }
        else{
            Recovery();
        }
    });
    for(let i=0; i<N; i++){
        if(node[i].live){
            answer += "O";
        }
        else{
            answer += "X";
        }
    }
    return answer;
}