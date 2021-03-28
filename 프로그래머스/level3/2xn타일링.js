function solution(n) {
    var answer = 0;
    let dp = [0, 1, 2];
    for(let i=3; i<=n; i++){
        dp.push((dp[i-2]+dp[i-1])%1000000007);
    }
    // console.log(dp);
    answer = dp[n];
    return answer;
}