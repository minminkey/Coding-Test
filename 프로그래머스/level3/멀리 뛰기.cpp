#include <string>
#include <vector>

using namespace std;

int dp[2001];

long long solution(int n) {
    long long answer = 0;
    dp[0] = 1;
    dp[1] = 2;
    for(int i=2; i<n; i++){
        dp[i] = (dp[i-1]+dp[i-2])%1234567;
    }
    answer = dp[n-1];
    return answer;
}