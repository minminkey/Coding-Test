function solution(sizes) {
    var answer = 0;
    let h = 0;
    let w = 0;
    for(let i=0; i<sizes.length; i++){
        if(sizes[i][0]<=sizes[i][1]){
            h = Math.max(h, sizes[i][1]);
            w = Math.max(w, sizes[i][0]);
        }
        else{
            w = Math.max(w, sizes[i][1]);
            h = Math.max(h, sizes[i][0]);
        }
    }
    answer = h*w;
    return answer;
}