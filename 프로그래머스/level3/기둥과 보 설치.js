let pillmap = [];
let dammap = [];
let n;

const ckPill = (x, y) => {
    if(y===0)   return true;
    if(y-1>=0&&pillmap[y-1][x]===1){
        return true;
    }
    if((dammap[y][x]===1)||(x-1>=0&&dammap[y][x-1]===1)){
        return true;
    }
    return false;
}

const ckDam = (x, y) => {
    if((y-1>=0&&pillmap[y-1][x]===1)||(y-1>=0&&x+1<=n&&pillmap[y-1][x+1]===1))  return true;
    if(x-1>=0&&x+1<=n&&dammap[y][x-1]===1&&dammap[y][x+1]===1)  return true;
    return false;
}

const buildPil = (info) => {
    let [x, y] = info;
    let flag = 0;
    if(pillmap[y][x]===1)   return;
    if(ckPill(x, y))    pillmap[y][x] = 1;
}

const buildDam = (info) => {
    let [x, y] = info;
    let flag = 0;
    if(dammap[y][x] === 1)    return;
    if(ckDam(x, y))     dammap[y][x] = 1;
}

const deletePil = (info) => {
    let [x, y] = info;
    let flag = 0;
    pillmap[y][x] = 0;
    for(let i=0; i<=n+1; i++){
        for(let j=0; j<=n+1; j++){
            if(pillmap[i][j]===1&&!ckPill(j, i))    flag = 1;
            if(dammap[i][j]===1&&!ckDam(j, i))    flag = 2;
            if(flag!==0)   break;
        }
        if(flag!==0)    break;
    }
    if(flag !== 0)   pillmap[y][x] = 1;
}

const deleteDam = (info) => {
    let [x, y] = info;
    let flag = 0
    dammap[y][x] = 0;
    for(let i=0; i<=n+1; i++){
        for(let j=0; j<=n+1; j++){
            if(pillmap[i][j]===1&&!ckPill(j, i))    flag = 1;
            if(dammap[i][j]===1&&!ckDam(j, i))    flag = 1;
            if(flag!==0)    break;
        }
        if(flag!==0)    break;
    }
    if(flag !== 0)  dammap[y][x] = 1;
}


function solution(N, build_frame) {
    n = N;
    for(let i=0; i<n+2; i++){
        pillmap.push(new Array(n+2).fill(0));
        dammap.push(new Array(n+2).fill(0));
    }
    var answer = [];
    build_frame.forEach(frame => {
        if(frame[2]===0){
            if(frame[3]===1){
                buildPil(frame);
            }
            else{
                deletePil(frame);
            }
        }
        else{
            if(frame[3]===1){
                buildDam(frame);
            }
            else{
                deleteDam(frame);
            }
        }
    });
    for(let j=0; j<=n; j++){
        for(let i=0; i<=n; i++){
            if(pillmap[i][j]===1)   answer.push([j, i, 0]);
            if(dammap[i][j]===1)   answer.push([j, i, 1]);
        }
    }
    answer.sort((a,b)=>{
        if(a[0]===b[0]){
            if(a[1]===b[1]) return a[2]-b[2];
            return a[1]-b[1];
        }
        return a[0]-b[0];
    });
    return answer;
}