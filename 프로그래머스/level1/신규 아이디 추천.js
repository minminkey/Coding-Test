const step = (str) => {
    str = str.toLowerCase();
    let ans = "";
    for(let i=0; i<str.length; i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='0'&&str[i]<='9')||str[i]==="-"||str[i]==="_"||str[i]==="."){
            ans += str[i];
        }
    }
    let ans2 = ans[0];
    for(let i=1; i<ans.length; i++){
        if(ans2[ans2.length-1]==='.'&&ans[i]==='.')   continue;
        ans2 += ans[i];
    }
    if(ans2[0]==='.'){
        ans2 = ans2.slice(1);
    }
    if(ans2[ans2.length-1]==='.'){
        ans2 = ans2.slice(0, ans2.length-1);
    }
    if(ans2.length===0){
        ans2 += 'a';
    }
    if(ans2.length>=16){
        ans2 = ans2.slice(0,15);
    }
    if(ans2[ans2.length-1]==='.'){
        ans2 = ans2.slice(0, ans2.length-1);
    }
    if(ans2.length<=2){
        while(ans2.length!==3){
            ans2 += ans2[ans2.length-1];
        }
    }
    return ans2;
}

function solution(new_id) {
    var answer = '';
    answer = step(new_id);
    return answer;
}