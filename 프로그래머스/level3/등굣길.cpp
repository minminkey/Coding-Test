#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[110][110];
bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0])  return a[1]>b[1];
    return a[0]>b[0];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    sort(puddles.begin(), puddles.end(), cmp);
    int answer = 0;
    map[1][1] = 1;
    vector<int> tmp = puddles.back();   
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(i==1&&j==1)  continue;
            if(i==tmp[0]&&j==tmp[1]){
                puddles.pop_back();
                if(puddles.empty()) continue;
                tmp = puddles.back();
                map[i][j] = 0;
                continue;
            }
            map[i][j] = (map[i-1][j] + map[i][j-1])%1000000007;
        }
    }
    answer = map[m][n];
    return answer;
}