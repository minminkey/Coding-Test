function solution(numbers, hand) {
    var answer = '';
    let obj = {};
    let r = 0;
    let c = 0;
    for(let i=1; i<=9; i++){
        obj[i] = [r,c];
        c++;
        if(c>=3){
            c=0;
            r++;
        }
    }
    obj['*'] = [3,0];
    obj[0] = [3,1];
    obj['#'] = [3,2];
    let left = '*';
    let right = '#';
    for(let i=0; i<numbers.length; i++){
        let lr = obj[left][0];
        let lc = obj[left][1];
        let rr = obj[right][0];
        let rc = obj[right][1];
        let tr = obj[numbers[i]][0];
        let tc = obj[numbers[i]][1];
        let l = Math.abs(lr-tr) + Math.abs(lc-tc);
        let r = Math.abs(rr-tr) + Math.abs(rc-tc);
        let flag = 0;
        if(numbers[i]===1||numbers[i]===4||numbers[i]===7){
            flag = 0;
        }
        else if(numbers[i]===3||numbers[i]===6||numbers[i]===9){
            flag = 1;
        }
        else{
            if(l<r){
                flag = 0;
            }
            else if(l>r){
                flag = 1;
            }
            else if(hand==="right"){
                flag = 1;
            }
        }
        if(flag===0){
            answer += "L";
            left = numbers[i];
        }
        else{
            answer += "R";
            right = numbers[i];
        }
        
    }
    return answer;
}