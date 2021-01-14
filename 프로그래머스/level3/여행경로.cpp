function solution(tickets) {
    var answer = [];
    var tmp = ["ICN"];
    let flag = 0;
    let visit = tickets.map(x => 0);
    tickets.sort(function(a,b) {
        if(a[0]===b[0]){
            if(a[1]<b[1])   return -1;
            else            return 1;
        } 
        else{
            if(a[0]<b[0])   return -1;
            else            return 1;
        }
    });
    let dfs = (target, tmp) => {
        let result = visit.every(x=>{
            return x===1;
        });
        if(result&&flag===0){
            tmp.map(x=>answer.push(x));
            flag = 1;
        }
        for(let i=0; i<tickets.length; i++){
            if(visit[i]===1) continue;
            if(tickets[i][0]===target){
                visit[i] = 1;
                tmp.push(tickets[i][1]);
                dfs(tickets[i][1], tmp);
                visit[i] = 0;
                tmp.pop();
            }
        }
        return
    }
    dfs("ICN", tmp);
    return answer;
}