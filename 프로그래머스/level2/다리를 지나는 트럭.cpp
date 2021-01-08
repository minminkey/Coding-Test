#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue <int> q;
    vector<int> truck;
    for(int i=0; i<truck_weights.size(); i++){
        q.push(truck_weights[i]);
    }
    int start = 0;
    int num = 0;
    int remain = weight;
    while(start<truck_weights.size()){
        answer++;
        for(int i=start; i<num; i++){
            truck[i]++;
            if(truck[i]>bridge_length){
                remain += truck_weights[i];
                start++;
            }
        }
        if(remain>=q.front()&&!q.empty()){
            num++;
            remain -= q.front();
            truck.push_back(1);
            q.pop();
        }
    }
    return answer;
}