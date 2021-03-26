function solution(m, musicinfos) {
    var answer = '';
    let infos = [];
    m = m.replace(/\w#/g, a => a[0].toLowerCase());
    musicinfos.forEach(str => {
        let tmp = str.split(',');
        let time = Number(tmp[1].substr(0,2))*60+Number(tmp[1].substr(3,2)) - Number(tmp[0].substr(0,2))*60-Number(tmp[0].substr(3,2));
        let result = [time, tmp[2], tmp[3]];
        infos.push(result);
    })
    let flag = 0;
    infos.forEach(info=>{
        info[2] = info[2].replace(/\w#/g, a => a[0].toLowerCase());
        
        while(info[0]>=info[2].length){
            info[2] += info[2];
        }
        info[2] = info[2].substr(0, info[0]);
        for(let i=0; i<=info[2].length-m.length; i++){
            let now = info[2].substr(i, m.length);
            if(now===m&&flag<info[0]){
                answer = info[1];
                flag = info[0];
            }
        }
    })
    if(answer === ""){
        return '(None)';
    }
    else    return answer
}