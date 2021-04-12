#include <string>
#include <vector>

using namespace std;

long long dp[5001] = {0, };

int solution(int n) {
    int answer = 0;
    dp[0] = 1;
    dp[2] = 3;
    long long tmp = 0;
    for(int i=4; i<=n; i+=2){
        tmp = (tmp+dp[i-4]*2)%1000000007;
        dp[i] = (dp[i-2]*3 + tmp)%1000000007;        
    }
    answer = dp[n];
    return answer;
}