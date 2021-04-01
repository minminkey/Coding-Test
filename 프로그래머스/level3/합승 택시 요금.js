function solution(n, s, a, b, fares) {
    let inf = 0x3f3f3f3f;
    var answer = inf;
    let mp = Array(n+1);
    for(let i=0; i<=n; i++){
        mp[i] = new Array(n+1).fill(inf);
    }
    fares.forEach(fare=>{
       mp[fare[0]][fare[1]] = fare[2]; 
       mp[fare[1]][fare[0]] = fare[2]; 
    });
    let real = mp.slice();
    for(let k=1; k<=n; k++){
        for(let i=1; i<=n; i++){
            for(let j=1; j<=n; j++){
                if(i===j)   real[i][j] = 0;
                else{
                    real[i][j] = Math.min(real[i][j], real[i][k]+mp[k][j]);
                }
            }
        }
    }
    // console.log(real);
    // console.log(real[3][4]);
    for(let i=1; i<=n; i++){
        answer = Math.min(answer, real[s][i]+real[i][a]+real[i][b]);
        // console.log(i, answer,real[s][i],real[i][a],real[i][b]);
    }
    return answer;
}