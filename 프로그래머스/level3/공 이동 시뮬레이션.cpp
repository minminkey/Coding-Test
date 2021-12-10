#include <string>
#include <vector>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    long long rowS = x, rowE = x;
    long long colS = y, colE = y;
    for(int i=queries.size()-1; i>=0;  i--){
        int d = queries[i][0];
        int dist = queries[i][1];
        if(d == 0){
            if(colS != 0)   colS += dist;
            colE += dist;
            if(colE > m-1)  colE = m-1;
        }
        else if(d == 1){
            if(colE != m-1) colE -= dist;
            colS -= dist;
            if(colS < 0)    colS = 0;
        }
        else if(d == 2){
            if(rowS != 0)   rowS += dist;
            rowE += dist;
            if(rowE > n-1)  rowE = n-1;
        }
        else if(d == 3){
            if(rowE != n-1) rowE -= dist;
            rowS -= dist;
            if(rowS < 0)    rowS = 0;
        }
        if(rowS>n-1||rowE<0||colS>m-1||colE<0)  return answer;
    }
    answer = (rowE-rowS+1) * (colE-colS+1);
    return answer;
}