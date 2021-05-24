#include <string>
#include <vector>

using namespace std;

int dp[15] = {0,};

int solution(int n) {
    int answer = 0;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){ 
            for(int j=1; j<=i; j++){
                dp[i] += dp[i-j] * dp[j-1]; 
            }
        }
    answer = dp[n];
    return answer;
}