function solution(record) {
    var answer = [];
    let info = {};
    let res = [];
    record.forEach(s => {
        let arr = s.split(' ');
        if(arr[0] === "Enter"){
            info[arr[1]] = arr[2];
            res.push([arr[1], 0]);
        }
        else if(arr[0] === "Leave"){
            res.push([arr[1], 1]);
        }
        else{
            info[arr[1]] = arr[2];
        }
    });
    res.forEach(x => {
        let str = info[x[0]];
        if(x[1] == 0){
            str += "님이 들어왔습니다.";
        }
        else{
            str += "님이 나갔습니다.";
        }
        answer.push(str);
    });
    return answer;
    
}