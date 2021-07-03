let obj = [];

const dfs =(str, now, idx) => {
    for(let i=idx; i<str.length; i++){
        let next = now + str[i];
        if(next.length>1){
            if(obj[next] === undefined) obj[next] = 0;
            obj[next]++;
        }
        dfs(str, next, i+1);
    }
}

function solution(orders, course) {
    var answer = [];
    let Max = new Array(11).fill(0);
    orders = orders.map(order=>order.split("").sort());
    orders.forEach(order=>dfs(order, "", 0));
    for(let str in obj){
        Max[str.length] = Math.max(Max[str.length], obj[str]);
    }
    for(let i=0; i<course.length; i++){
        for(let str in obj){
            if(str.length === course[i] && Max[str.length] === obj[str] && obj[str]>1){
                answer.push(str);
            }
        }    
    }
    
    if(answer.length === 0) answer.push("");
    return answer.sort();
}