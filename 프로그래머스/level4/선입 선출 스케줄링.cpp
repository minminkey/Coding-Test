#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int start = 0;
    int end = 10000*n;
    int target = end+1;
    if(n<=cores.size()){
        return n;
    }
    while(start<=end){
        int mid = (start+end)/2;
        int sum = 0;
        for(int i=0; i<cores.size(); i++){
            sum += mid/cores[i] + 1;
        }
        if(sum>=n){
            target = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    int cnt = 0;
    int gap = 0;
    for(int  i=0; i<cores.size(); i++){
        if(target%cores[i]==0){
            gap += target/cores[i];
        }
        else{
            gap += target/cores[i] + 1;
        }
    }
    for(int  i=0; i<cores.size(); i++){
        if(target%cores[i]==0){
            gap++;
            if(gap==n){
                answer = i+1;
                break;
            }
        }
    }
    return answer;
}