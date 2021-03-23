let parent = [];

function findParent(child){
    if(parent[child] === child){
        return child;
    }
    else return findParent(parent[child]);
}

function solution(n, costs) {
    let answer = 0;
    let visit = Array(n).fill(0);
    for(let i=0; i<n; i++){
        parent.push(i);
    }
    costs.sort((a,b)=>{
        if(a[2] == b[2]){
            return a[0] - b[0];
        }
       return a[2] - b[2]; 
    });
    for(let i=0; i<costs.length; i++){
        let s = costs[i][0];
        let e = costs[i][1];
        let cost = costs[i][2];
        if(findParent(s) !== findParent(e)){
            answer += cost;
            parent[findParent(s)] = findParent(e);
            visit[e] = 1;
        }
    }
    return answer;
}