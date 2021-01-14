function solution(triangle) {
    var answer = 0;
    let size = triangle.length;
    for(let i = 1; i<size; i++){
        triangle[i][0] += triangle[i-1][0];
        for(let j=1; j<i; j++){
            triangle[i][j] += Math.max(triangle[i-1][j-1], triangle[i-1][j]);
        }
        triangle[i][i] += triangle[i-1][i-1];
    }
    for(let i = 0; i<size; i++){
        answer = Math.max(answer, triangle[size-1][i]);
    }
    return answer;
}