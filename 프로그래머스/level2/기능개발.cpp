#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> s) {
    vector<int> answer;
    vector<int> speeds = s;
    queue <int> q;
    for(int i=0; i<progresses.size(); i++){
        q.push(progresses[i]);
    }
    int index = 0;
    while(1){
        int sum = 0;
        while(q.front()+speeds[index]>=100){
            q.pop();
            index++;
            sum++;
            if(q.empty())   break;
        }
        if(sum!=0)  
            answer.push_back(sum);
        if(q.empty())   break;
        for(int i=0; i<speeds.size(); i++){
            speeds[i] += s[i];
        }
    }
    return answer;
}
