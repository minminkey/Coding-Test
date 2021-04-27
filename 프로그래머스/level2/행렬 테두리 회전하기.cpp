#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mp[111][111];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int foo = 1;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            mp[i][j] = foo++;
        }
    }
    for(int i=0; i<queries.size(); i++){
        int sr = queries[i][0];
        int sc = queries[i][1];
        int er = queries[i][2];
        int ec = queries[i][3];
        int tmp = mp[sr][sc];
        int minValue = tmp;
        for(int r=sr; r<=er-1; r++){
            mp[r][sc] = mp[r+1][sc];
            minValue = min(minValue, mp[r][sc]);
        }
        for(int c=sc; c<=ec-1; c++){
            mp[er][c] = mp[er][c+1];
            minValue = min(minValue, mp[er][c]);
        }
        for(int r=er; r>=sr+1; r--){
            mp[r][ec] = mp[r-1][ec];
            minValue = min(minValue, mp[r][ec]);
        }
        for(int c=ec; c>=sc+2; c--){
            mp[sr][c] = mp[sr][c-1];
            minValue = min(minValue, mp[sr][c]);
        }
        mp[sr][sc+1] = tmp;
        answer.push_back(minValue);
    }
    return answer;
}