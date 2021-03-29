function solution(dartResult) {
    var answer = 0;
    let results = dartResult.match(/\d.\D?/g);
    let type = {'S':1, 'D':2, 'T':3};
    let entity = [];
    results.forEach(result => {
        let sp = result.match(/(^\d{1,})(S|D|T)(\*|#)?/);
        let point = Math.pow(Number(sp[1]), type[sp[2]]);
        let option = 1;
        if(sp[3]!==undefined)   option = sp[3]==='#' ? -1 : 2;
        if(option===-1){
            point = -1*point;
        }
        entity.push(point);
        if(option===2){
            entity[entity.length-1] *= 2;
            if(entity.length>1)    entity[entity.length-2] *= 2;
        }
    });
    entity.forEach(x=>answer+=x);
    return answer;
}