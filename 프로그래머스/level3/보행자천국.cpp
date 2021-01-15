#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int dp[501][501][2];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dp[i][j][0]=0;
            dp[i][j][1]=0;
        }
    }
    dp[0][0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(city_map[i][j]==1)   continue;
            else if(city_map[i][j]==0){
                dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0] + dp[i][j][1])%MOD;
                dp[i][j+1][1] = (dp[i][j+1][1] + dp[i][j][0] + dp[i][j][1])%MOD;
            }
            else{
                dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0])%MOD;
                dp[i][j+1][1] = (dp[i][j+1][1] + dp[i][j][1])%MOD;
            }
        }
    }
    answer = (dp[m-1][n-1][0] + dp[m-1][n-1][1])%MOD;
    return answer;
}