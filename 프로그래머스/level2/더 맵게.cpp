#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<scoville.size(); i++){
        q.push(scoville[i]);
    }
    while(q.top() < K && q.size()>1){
        int s1 = q.top();
        q.pop();
        int s2 = q.top();
        q.pop();
        q.push(s1 + 2*s2);
        answer++;
    }
    if(q.top()<K)  return -1;
    return answer;
}