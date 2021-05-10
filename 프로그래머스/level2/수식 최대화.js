let exp = (a, b, ex) => {
    if(ex==='*')        return a*b;
    else if(ex==='+')   return a+b;
    else                return a-b;
}

function solution(expression) {
    var answer = 0;
    let orders = [['+','-','*'], ['+','*','-'], ['-','+','*'], ['-','*','+'], ['*','-','+'], ['*','+','-']];
    orders.forEach(order=>{
        let numbers = expression.split(/([+\-*/])/);
        for(let i=0; i<order.length; i++){
            let ex = order[i];
            let tmp = [];
            for(let n=0; n<numbers.length; n++){
                if(numbers[n]===ex){
                    let a = Number(tmp[tmp.length-1]);
                    let b = Number(numbers[n+1]);
                    tmp.pop();
                    tmp.push(exp(a,b,numbers[n]));
                    n++;
                }
                else{
                    tmp.push(numbers[n]);
                }
            }
            numbers = tmp.slice(0);
        }
        answer = Math.max(answer, Math.abs(Number(numbers[0])));
    })
    return answer;
}