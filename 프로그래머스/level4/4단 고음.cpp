#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int answer = 0;

void dfs(int now, int st){
    if(now<3 || 2*log(now)/log(3)<st)   return;
    if(now == 3 && st == 2){
        answer++;   
        return;
    }
    if(now%3 == 0 && st>=2){
        dfs(now/3, st-2);
    }
    dfs(now-1, st+1);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    answer = 0;
    dfs(n-2, 2);
    return answer;
}