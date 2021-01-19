function ck(target, banned){
    if(target.length!==banned.length)  return false;
    for(let i=0; i<target.length; i++){
        if(banned[i]=='*')  continue;
        if(target[i]!==banned[i])   return false;
    }
    return true;
}
function solution(user_id, banned_id) {
    var answer = 0;
    let visit = user_id.map(x=>0);
    let limit = banned_id.length;
    let ans = [];
    function dfs(idx, visit){
        if(idx===limit){
            let tmp = "";
            visit.map(x=>tmp+=('0'+x));
            for(let i=0; i<ans.length; i++){
                if(ans[i]===tmp)    return;
            }
            ans.push(tmp);
            answer++;
            return;
        }
        for(let i=0; i<user_id.length; i++){
            if(ck(user_id[i], banned_id[idx])&&visit[i]===0){
                visit[i] = 1;
                dfs(idx+1, visit);
                visit[i] = 0;
            }
        }
    }
    dfs(0, visit);
    return answer;
}