const classfy = (str) => {
    let arr = str.split(" ");
    let ans = [];
    for(let i=0; i<4; i++){
        if(arr[i]==="python")   ans.push("3");
        else if(arr[i]==="java")   ans.push("2");
        else if(arr[i][0] === 'c'||arr[i][0] === 'b'||arr[i][0] === 'j')  ans.push("1");
        else if(arr[i][0] === 'f'||arr[i][0] === 's'||arr[i][0] === 'p')  ans.push("2");
    }
    ans.push(Number(arr[4]));
    return ans;
}

function solution(info, query) {
    var answer = [];
    let obj = {};
    info.forEach(str => {
        let tmp = [];
        let arr = classfy(str);
        for(let i=0; i<4; i++){
            let cp = tmp.slice();
            tmp = [];
            if(cp.length===0){
                tmp.push(arr[i]);
                tmp.push("0");
            }
            else{
                for(let j=0; j<cp.length; j++){
                    tmp.push(cp[j] + arr[i]);
                    tmp.push(cp[j] + "0");
                }
            }
        }
        tmp.forEach(str => {
            if(obj[str] === undefined){
                obj[str] = [arr[4]];
            }
            else{
                obj[str].push(arr[4]);   
            }
        });
    });
    for(const now in obj){
        obj[now] = obj[now].sort((a,b)=>a-b);
    }
    query.forEach(q => {
        let tmp = q.split(" ");
        let arr = [];
        for(let i=0; i<=6; i+=2){
            arr.push(tmp[i]);
        }
        let num = Number(tmp[7]);
        let str = "";
        for(let i=0; i<arr.length; i++){
            if(arr[i]==="python")   str += "3";
            else if(arr[i]==="java")   str += "2";
            else if(arr[i][0] === 'c'||arr[i][0] === 'b'||arr[i][0] === 'j')  str += "1";
            else if(arr[i][0] === 'f'||arr[i][0] === 's'||arr[i][0] === 'p')  str += "2";
            else if(arr[i]==='-')   str+="0";
        }
        if(obj[str] === undefined){
            answer.push(0);
        }
        else{
            let idx = obj[str].length;
            let s = 0;
            let e = obj[str].length;
            while(s<=e){
                let mid = Math.floor((s+e)/2);
                if(obj[str][mid]>=num){
                    idx = mid;
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            answer.push(obj[str].length-idx);
        }
        
    });
    return answer;
}