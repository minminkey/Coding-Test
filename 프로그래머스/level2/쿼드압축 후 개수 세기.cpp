#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> arr;

int cnt[2];

void divide(int size, int r, int c){
    int target = arr[r][c];
    int flag = 0;
    for(int i=r; i<size+r; i++){
        for(int j=c; j<size+c; j++){
            if(arr[i][j]!=target){
                flag = 1;
                break;
            }
        }
    }
    if(flag==0){
        cnt[target]++;
    }
    else{
        divide(size/2, r, c);
        divide(size/2, r+size/2, c);
        divide(size/2, r, c+size/2);
        divide(size/2, r+size/2, c+size/2);
    }
}
vector<int> solution(vector<vector<int>> Arr) {
    vector<int> answer;
    arr = Arr;
    divide(arr.size(), 0, 0);
    answer.push_back(cnt[0]);
    answer.push_back(cnt[1]);
    return answer;
}