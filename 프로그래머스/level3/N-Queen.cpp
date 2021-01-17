#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;
int n;
void dfs(vector<vector<int>> map, int row){
    if(row==n){
        cnt++;
        return;
    }
    for(int j=0; j<n; j++){
        vector<vector<int>> tmp = map;
        if(map[row][j]==1)    continue;
        tmp[row][j] = 1;
        int l = j-1;
        int m = j;
        int r = j+1;
        for(int i=row+1; i<n; i++){
            tmp[i][m] = 1;
            if(l>=0){
                tmp[i][l] = 1;
                l--;
            }
            if(r<n){
                tmp[i][r] = 1;
                r++;
            }
        }
        dfs(tmp, row+1);
    }
}
int solution(int N) {
    n = N;
    int answer = 0;
    vector<vector<int>> map;
    for(int i=0; i<n; i++){
        vector<int> tmp;
        for(int j=0; j<n; j++){
            tmp.push_back(0);
        }
        map.push_back(tmp);
    }
    dfs(map, 0);
    answer = cnt;
    return answer;
}