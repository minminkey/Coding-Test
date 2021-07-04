function solution(money, cost) {
    var answer = -1;
    let st = 0;
    let ed = 0;
    let now = 0;
    let long = 0;
    for(let ed=0; ed<cost.length; ed++){
        let flag = 0;
        now += cost[ed];
        while(now > money){
            now -= cost[st];
            st++;
            if(st>ed){
                flag = 1;
                break;
            }
        }
        long = Math.max(long, ed-st+1);
    }
    return long;
}