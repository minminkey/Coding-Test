function solution(record) {
    var answer = [];
    let ans = [];
    let infos = record.map(str=>str.split(' '));
    let obj = {};
    infos.forEach(info => {
        if(info[0] === "Enter"){
            obj[info[1]] = info[2];
            answer.push([0, info[1]]);
        }
        else if(info[0] === "Leave"){
            answer.push([1, info[1]]);
        }
        else if(info[0] === "Change"){
            obj[info[1]] = info[2];
        }
    });
    ans = answer.map(a=>{
        let res = obj[a[1]];
        if(a[0] === 0){
            res += "님이 들어왔습니다.";
        }
        else if(a[0] === 1){
            res += "님이 나갔습니다.";
        }
        return res;
    })
    return ans;
}