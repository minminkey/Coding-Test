#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    vector<int> avg;
    for(int c=0; c<scores[0].size(); c++){
        int Max = -1;
        int Min = 101;
        int maxCnt = 0;
        int minCnt = 0;
        for(int r=0; r<scores.size(); r++){
            if(Max<scores[r][c]){
                maxCnt = 1;
                Max = scores[r][c];
            }
            else if(Min > scores[r][c]){
                minCnt = 1;
                Min = scores[r][c];
            }
            else if(Max == scores[r][c])    maxCnt++;
            else if(Min == scores[r][c])    minCnt++;
        }
        cout<<Max<<' '<<Min<<' '<<maxCnt<<' '<<minCnt<<endl;
        if(scores[c][c]==Max&&maxCnt == 1){
            scores[c][c] = -1;
        }
        else if(scores[c][c]==Min&&minCnt == 1){
            scores[c][c] = -1;
        }
    }
    for(int i=0; i<scores.size(); i++){
        for(int j=0; j<scores[i].size(); j++){
            cout<<scores[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int c=0; c<scores[0].size(); c++){
        int cnt = 0;
        int sum = 0;
        for(int r=0; r<scores.size(); r++){
            if(scores[r][c] != -1){
                sum += scores[r][c];
                cnt++;
            }
        }
        int avg = sum/cnt;
        if(avg>=90){
            answer+="A";
        }
        else if(avg>=80)    answer+="B";
        else if(avg>=70)    answer+="C";
        else if(avg>=50)    answer+="D";
        else                answer+="F";
    }
    return answer;
}