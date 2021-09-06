function solution(weights, head2head) {
    var answer = [];
    let info = [];
    for(let i=0; i<head2head.length; i++){
        let s = head2head[i];
        let arr = [];
        let cnt = 0;
        let win = 0;
        let hwin = 0;
        for(let j=0; j<s.length; j++){
            // console.log(s[i]);
            if(s[j]!=="N"){
                cnt++;
                if(s[j]==="W"){
                    win++;
                    if(weights[i]<weights[j]){
                        hwin++;
                    }
                }
            }
        }
        if(cnt==0){
            arr.push(0);
        }
        else{
            arr.push(win/cnt);
        }
        arr.push(hwin);
        arr.push(weights[i]);
        arr.push(i+1);
        info.push(arr);
    }
    info.sort((a,b)=>{
        if(a[0]===b[0]){
            if(a[1]===b[1]){
                if(a[2] === b[2]){
                    return a[3] - b[3];
                }
                return b[2] - a[2];
            }
            return b[1] - a[1];
        }
        return b[0] - a[0];
    });
    answer = info.map(arr=>arr[3]);
    return answer;
}