#include <string>
#include <vector>
#include <iostream>

using namespace std;
int num[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    double half = (double)n/2.0;
    int sum = (1+n)*half;
    int startr = 1;
    int startc = 1;
    int cnt = 1;
    while(sum>=cnt){
        int row;
        int col;
        for(int i=startr; i<=n; i++){
            if(num[i][startc]!=0){
                break;
            }
            row = i;
            num[i][startc] = cnt++;
        }
        for(int i=startc+1; i<=row; i++){
            if(num[row][i]!=0){
                break;
            }
            col = i;
            num[row][i] = cnt++;
        }
        col--;
        for(int i=row-1; i>=startr+1; i--){
            num[i][col] = cnt++;
            col--;
        }
        startr += 2;
        startc++;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            // cout<<num[i][j]<<' ';
            answer.push_back(num[i][j]);
        }
        // cout<<endl;
    }
    return answer;
}
