//구현
function solution(places) {
    var answer = [];
    let room = [];
    let dr = [-1, 0, 0, 1, 1, 2];
    let dc = [1, 1, 2, 1, 0, 0];
    for(let i=0; i<5; i++){
        room.push(new Array(5).fill(0));
    }
    places.forEach(info => {
        for(let r=0; r<5; r++){
            for(let c=0; c<5; c++){
                room[r][c] = info[r][c];
            }
        }
        let flag = 1;
        for(let r=0; r<5; r++){
            for(let c=0; c<5; c++){
                if(room[r][c] !== 'P')  continue;
                for(let d=0; d<6; d++){
                    let nr = r+dr[d];
                    let nc = c+dc[d];
                    if(nr<0||nc<0||nr>=5||nc>=5)    continue;
                    if(room[nr][nc] !== 'P')          continue;
                    if(d === 0){
                        if(room[r-1][c] !== 'X' || room[r][c+1] !== 'X'){
                            flag = 0;
                        }
                    }
                    else if(d === 1)    flag = 0;
                    else if(d === 2 && room[r][c+1] !== 'X')    flag = 0;
                    else if(d === 3){
                        if(room[r][c+1] !== 'X' || room[r+1][c] !== 'X')    flag = 0;
                    }
                    else if(d === 4)    flag = 0;
                    else if(d === 5 && room[r+1][c] !== 'X')    flag = 0;
                    if(flag === 0)  break;
                }
                if(flag === 0)  break;
            }
            if(flag === 0)  break;
        }
        answer.push(flag);
    });
    return answer;
}