#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[1000000];
int dp1[1000000];

int solution(vector<int> money) {
    int answer = 0;
    dp[0] = money[0];
    dp[1] = max(money[0],money[1]);
    dp1[1] = money[1];
    for(int i=2; i<money.size(); i++){
        dp[i] = max(dp[i-1], dp[i-2]+money[i]);
        dp1[i] = max(dp1[i-1], dp1[i-2]+money[i]);
    }
    answer = max(dp1[money.size()-1], dp[money.size()-2]);
    return answer;
}