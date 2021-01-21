function solution(dirs) {
    var answer = 0;
    let h = Array.from(Array(10), () => Array(10).fill(0))
    let v = Array.from(Array(10), () => Array(10).fill(0))
    let r = 5;
    let c = 5;
    for(let i=0; i<dirs.length; i++){
        if(dirs[i] === 'U'){
            if(r-1<0)   continue;
            if(h[r-1][c]===0){
                answer++;
                h[r-1][c]=1;
            }
            r--;
            
        }
        else if(dirs[i] === 'R'){
            if(c+1>10)  continue;
            if(v[r][c]===0){
                answer++;
                v[r][c]=1;
            }
            c++;
        }
        else if(dirs[i] === 'D'){
            if(r+1>10)  continue;
            if(h[r][c]===0){
                answer++;
                h[r][c]=1;
            }
            r++;
        }
        else{
            if(c-1<0)   continue;
            if(v[r][c-1]===0){
                answer++;
                v[r][c-1]=1;
            }
            c--;
        }
    }
    return answer;
}