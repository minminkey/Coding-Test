#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[1]==b[1])  a[0]<b[1];
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int start = -40000;
    sort(routes.begin(), routes.end(), cmp);
    for(int i=0; i<routes.size(); i++){
        if(routes[i][0]>start){
            answer++;
            start = routes[i][1];
        }
    }
    return answer;
}