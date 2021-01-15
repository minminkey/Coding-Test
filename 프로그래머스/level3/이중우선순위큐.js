class PQ{
    constructor(){
        this._arr = [];
    }
    push(item){
        this._arr.push(item);
        this._arr.sort((a,b)=> a-b);
    }
    pop_front(){
        if(this._arr.length === 0) return;
        this._arr.shift();
    }
    pop_back(){
        if(this._arr.length === 0) return;
        this._arr.pop();
    }
    top(){
        return this._arr[0];
    }
    bottom(){
        return this._arr[this._arr.length-1];
    }
    empty(){
        if(this._arr.length===0)    return true;
        return false;
    }
}
function solution(operations) {
    var answer = [0, 0];
    const pq = new PQ;
    for(let i=0; i<operations.length; i++){
        let tmp = operations[i].split(' ');
        if(tmp[0]==="I"){
            pq.push(Number(tmp[1]));
        }
        else{
            if(tmp[1]==="1"){
                pq.pop_back();
            }
            else{
                pq.pop_front();
            }
        }
    }
    if(!pq.empty()){
        answer[0] = pq.bottom();
        answer[1] = pq.top();
    }
    return answer;
}