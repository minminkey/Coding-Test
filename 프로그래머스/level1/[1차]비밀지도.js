const Change = (num) => {
    let arr = [];
    while(num!==0){
        arr.unshift(num%2);
        num = Math.floor(num/2);
    }
    return arr;
}

function solution(n, arr1, arr2) {
    var answer = [];
    let map1 = [];
    let map2 = [];
    arr1.forEach(arr=>{
        let tmp = Change(arr);
        while(tmp.length<n){
            tmp.unshift(0);
        }
        map1.push(tmp);
    });
    arr2.forEach(arr=>{
        let tmp = Change(arr);
        while(tmp.length<n){
            tmp.unshift(0);
        }
        map2.push(tmp);
    });
    for(let i=0; i<n; i++){
        let str = "";
        for(let j=0; j<n; j++){
            if(map1[i][j]===0&&map2[i][j]===0)  str += " ";
            else                                str += "#";
        }
        answer.push(str);
    }
    return answer;
}