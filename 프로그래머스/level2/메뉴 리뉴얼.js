let obj = {};

const dfs = (str, n, now) => {
    for(let i=n; i<str.length; i++){
        let next = now + str[i];
        if(next.length > 1){
            if(obj[next]===undefined){
                obj[next] = 1;
            }
            else{
                obj[next]++;
            }
        }
        dfs(str, i+1, next);
    }
}

function solution(orders, course) {
    var answer = [];
    orders.forEach(order => {
        order = order.split("").sort().join("");
        dfs(order, 0, "");
    });
    course.forEach(num => {
        let maxNum = 0;
        for(const str in obj){
            if(str.length === num){
                maxNum = Math.max(maxNum, obj[str]);
            }
        }
        if(maxNum>=2){
            for(const str in obj){
                if(str.length === num&&obj[str]===maxNum){
                    answer.push(str);
                }
            }
        }
    })
    answer.sort();
    if(answer.length===0){
        answer.push("");
    }
    return answer;
}