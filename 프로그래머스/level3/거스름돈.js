function solution(n, money) {
    var answer = 0;
    let dp = [];
    for(let i=0; i<=n; i++){
        if(i%money[0] === 0)    dp.push(1);
        else                    dp.push(0);
    }
    for(let i=1; i<money.length; i++){
        for(let j=money[i]; j<=n; j++){
            dp[j] = (dp[j] + dp[j-money[i]])%1000000007;
        }
    }
    answer = dp[n];
    return answer;
}