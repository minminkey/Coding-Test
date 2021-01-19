class Queue{
    constructor(){
        this.arr = [];
    }
    push(value){
        this.arr.push(value);
        this.arr.sort((a,b)=>{
            if(a[1]===b[1]) a[0]-b[0];
            else            a[1]-b[1];
        })
    }
    pop(){
        this.arr.shift();
    }
    top(){
        return this.arr[0];
    }
    empty(){
        if(this.arr.length === 0)   return true;
        return false;
    }
}
function solution(N, road, K) {
    var answer = 0;
    const q = new Queue;
    let visit = [];
    for(let i=0; i<=N; i++){
        visit.push(0);
    }
    q.push([1, 0]);
    visit[1] = 1;
    while(!q.empty()){
        let node = q.top()[0];
        let value = q.top()[1];
        q.pop();
        for(let i=0; i<road.length; i++){
            let next;
            let nextValue = road[i][2];
            if(road[i][0]===node)   next = road[i][1];
            else if(road[i][1]===node)  next = road[i][0];
            if(visit[next]===0||visit[next]>value+nextValue){
                visit[next] = value+nextValue;
                q.push([next, value+nextValue]);
            }
        }
    }
    for(let i=1; i<=N; i++){
        if(visit[i]<=K)  answer++;
    }
    return answer;
}