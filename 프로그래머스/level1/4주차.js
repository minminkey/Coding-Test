function solution(table, languages, preference) {
    var answer = '';
    let maxRes = -1;
    table.forEach(str=>{
        let arr = str.split(' ');
        let obj = {};
        let point = 5;
        let res = 0;
        for(let i=1; i<arr.length; i++){
            obj[arr[i]] = point--;
        }
        for(let i=0; i<languages.length; i++){
            if(obj[languages[i]] !== undefined){
                res += preference[i] * obj[languages[i]];
            }
        }
        if(maxRes < res){
            maxRes = res;
            answer = arr[0];
        }
        else if(maxRes === res){
            if(answer > arr[0]){
                answer = arr[0];
            }
        }
    });
    return answer;
}