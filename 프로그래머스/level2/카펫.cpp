#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int base = (brown-4)/2;
    int limit = base/2;
    // cout<<limit<<' '<<base;
    for(int i=1; i<=limit; i++){
        int r = i;
        int c = base - i;
        if(r*c == yellow){
            answer.push_back(c+2);
            answer.push_back(r+2);
            break;
        }
    }
    return answer;
}