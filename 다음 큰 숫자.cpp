#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp = n;
    int cnt = 0;
    while(tmp!=0){
        if(tmp%2==1)    cnt++;
        tmp /= 2;
    }
    for(int i=n+1; i<=1000000; i++){
        int t = i;
        int c = 0;
        while(t!=0){
            if(t%2==1)    c++;
            t /= 2;
        }
        if(c==cnt)  return i;
    }
    return answer;
}