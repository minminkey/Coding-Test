#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int h = 0;
    int w = 0;
    for(int i=0; i<sizes.size(); i++){
        if(sizes[i][0]<=sizes[i][1]){
            h = max(h, sizes[i][1]);
            w = max(w, sizes[i][0]);
        }
        else{
            w = max(w, sizes[i][1]);
            h = max(h, sizes[i][0]);
        }
    }
    answer = h*w;
    return answer;
}