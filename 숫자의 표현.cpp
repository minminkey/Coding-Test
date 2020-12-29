#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1; i<=n/2; i++){
        int tmp = 0;
        for(int j=i; j<=n; j++){
            tmp += j;
            if(tmp == n){
                answer++;
                break;
            }    
            else if(tmp>n) break;
        }
    }
    return answer+1;
}