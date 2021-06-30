let visit = [];
let unique = [];
let ans = 0;

const ck = (relation, idxs) => {
    let obj = {};
    for(let i=0; i<relation.length; i++){
        let str = "";
        for(let j=0; j<idxs.length; j++){
            str += ' ' + relation[i][idxs[j]];
        }
        if(obj[str] !== undefined){
            return false;
        }
        obj[str] = str
    }
    return true;
}

const makeCk = (relation, cnt, idxs, st) => {
    if(cnt === 0){
        if(ck(relation, idxs)){
            unique.push(idxs.slice(0));
            ans++;
        }
        return;
    }
    for(let i=st; i<relation[0].length; i++){
        if(visit[i]===1)    continue;
        idxs.push(i);
        visit[i] = 1;
        let flag = 0;
        for(let i=0; i<unique.length; i++){
            let foo = 1;
            for(let j=0; j<unique[i].length; j++){
                if(idxs.find(idx=>idx===unique[i][j]) === undefined)    foo = 0;
            }
            if(foo===1){
                flag = 1;
                break;
            }
        }
        if(flag === 0)  makeCk(relation, cnt-1, idxs, i+1)
        visit[i] = 0;
        idxs.pop();
    }
}

function solution(relation) {
    var answer = 0;
    for(let i=0; i<relation[0].length; i++){
        visit.push(0);
    }
    for(let i=1; i<=relation[0].length; i++){
        let idxs = [];
        makeCk(relation, i, idxs, 0);
    }
    answer = ans;
    return answer;
}