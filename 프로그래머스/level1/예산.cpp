#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    vector<int> tmp = d;
    int t = budget;
    sort(tmp.begin(), tmp.end());
    for(int i=0; i<tmp.size(); i++){
        if(t-tmp[i]>=0){
            answer++;
            t -= tmp[i];
        }
    }
    return answer;
}