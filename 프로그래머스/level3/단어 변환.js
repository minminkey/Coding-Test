class Queue {
    constructor() {
        this._arr = [];
    }
    push(item) {
        this._arr.push(item);
    }
    empty(){
        if(this._arr.length === 0)   return true;
        else                        return false;
    }
    top(){
        return this._arr[0];
    }
    pop() {
        return this._arr.shift();
    }
}

const findOne = (now, next) => {
    let diff = 0;
    for(let i=0; i<now.length; i++){
        if(now[i]===next[i])    continue;
        diff++;
    }
    if(diff>1)  return false;
    else        return true;
}

function solution(begin, target, words) {
    var answer = -1;
    const q = new Queue;
    let visit = Array(words.length).fill(0);
    q.push([begin, 0]);
    while(!q.empty()){
        let now = q.top()[0];
        let cnt = q.top()[1];
        q.pop();
        for(let i=0; i<words.length; i++){
            if(visit[i]===1)    continue;
            if(findOne(now, words[i])){
                if(words[i]===target){
                    answer = cnt+1;
                    break;
                }
                visit[i] = 1;
                q.push([words[i], cnt+1]);
            }
        }
        if(answer!==-1){
            break;
        }
    }
    if(answer===-1){
        answer = 0;    
    }
    return answer;
}