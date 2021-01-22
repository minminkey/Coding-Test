#include <vector>
#include <iostream>
#include <algorithm>

#define INF 2e9

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    vector<int> Map[210];
    vector<vector<int>> dp(k, vector<int>(n + 1, INF));
    for(int i=0; i<edge_list.size(); i++){
        Map[edge_list[i][0]].push_back(edge_list[i][1]);
        Map[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    dp[0][gps_log[0]] = 0;
    for(int i=1; i<k; i++){
        for(int j=1; j<=n; j++){
            if(dp[i-1][j]==INF) continue;
            for(int x=0; x<Map[j].size(); x++){
                int next = Map[j][x];
                int a = 1;
                if(next == gps_log[i])  a--;
                dp[i][next] = min(dp[i][next], dp[i-1][j] + a);
            }
        }
    }
    if(dp[k-1][gps_log[k-1]]<INF)   return dp[k-1][gps_log[k-1]];
    return -1;
}