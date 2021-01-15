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
function solution(n, edge) {
    var answer = 0;
    let cnt = 0;
    let visit = []
    let e =[];
    for(let i=0; i<=n; i++){
        visit.push(0);
        e.push([]);
    }
    const queue = new Queue();
    queue.push(1);
    for(let i = 0; i<edge.length; i++){
        let tmp = edge[i][0];
        let tmp2 = edge[i][1];
        e[tmp].push(edge[i][1]);
        e[tmp2].push(edge[i][0]);
    }
    while(!queue.empty()){
        let now = queue.top();
        queue.pop();
        cnt = visit[now]+1;
        for(let i=0; i<e[now].length; i++){
            if(visit[e[now][i]]===0&&e[now][i]!==1){
                queue.push(e[now][i]);
                visit[e[now][i]] = cnt;
            }
        }
    }
    cnt--;
    for(let i=1; i<=n; i++){
        if(visit[i]===cnt)  answer++;
    }
    return answer;
}