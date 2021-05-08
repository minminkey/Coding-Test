let obj = new Map();

let Find = (want) => {
    if(obj.get(want)===undefined){
        obj.set(want, want+1);
        return want;
    }
    obj.set(want, Find(obj.get(want)));
    return obj.get(want);
}

function solution(k, room_number) {
    var answer = [];
    room_number.forEach(num=>{
        let result = Find(num);
        answer.push(result);
    });
    return answer;
}