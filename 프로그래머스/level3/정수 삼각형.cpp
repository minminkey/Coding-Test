#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp;
    vector<int> tmp;
    tmp.push_back(triangle[0][0]);
    dp.push_back(tmp);
    for(int i=1; i<triangle.size(); i++){
        vector<int> tmp;
        for(int j=0; j<triangle[i].size(); j++){
            if(j==0){
                tmp.push_back(triangle[i][0] + dp[i-1][0]);
            }
            else if(j==triangle[i].size()-1){
                tmp.push_back(triangle[i][j] + dp[i-1][j-1]);
            }
            else{
                tmp.push_back(max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]);
            }
            answer = max(answer, tmp[j]);
        }
        dp.push_back(tmp);
    }
    return answer;
}