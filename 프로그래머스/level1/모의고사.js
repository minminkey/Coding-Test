let per = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]];
function solution(answers) {
    var answer = [];
    let grade = [];
    let maxCnt = 0;
    for(let i=0; i<3; i++){
        let si = per[i].length;
        let cnt = 0;
        for(let j=0; j<answers.length; j++){
            if(answers[j] == per[i][j%si])  cnt++;
        }
        maxCnt = Math.max(maxCnt, cnt);
        grade.push(cnt);
    }
    for(let i=0; i<3; i++){
        if(grade[i]==maxCnt)    answer.push(i+1);
    }
    return answer;
}