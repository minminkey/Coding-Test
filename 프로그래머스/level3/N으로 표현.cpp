#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = 10;
    unordered_set<int> s[8];
    int sum = 0;
    for(int i=0; i<8; i++){
        sum = sum*10+N;
        s[i].insert(sum);
        if(sum==number) answer = i+1;
    }
    for(int i=1; i<8; i++){
        for(int j=0; j<i; j++){
            for(auto& a : s[j]){
                for(auto& b : s[i-j-1]){
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if(b != 0)  s[i].insert(a / b);
                }
            }
        }
        if(s[i].find(number)!=s[i].end()){
            if(answer>i+1) answer = i+1;
            break;
        }
    }
    if(answer>8)    return -1;
    return answer;
}