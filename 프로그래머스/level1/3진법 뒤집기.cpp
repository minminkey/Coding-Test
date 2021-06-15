#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp = n;
    vector<int> v, t;
    while(tmp!=0){
        v.push_back(tmp%3);
        tmp /= 3;
    }
    for(int i=v.size()-1; i>=0; i--){
        t.push_back(v[i]);
    }
    int k = 1;
    for(int i=0; i<t.size(); i++){
        answer += k*t[i];
        k *= 3;
    }
    return answer;
}