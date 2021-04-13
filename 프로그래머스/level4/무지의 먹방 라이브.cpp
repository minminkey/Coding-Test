#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long foodSize = food_times.size();
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    for(int i=0; i<foodSize; i++){
        pq.push({food_times[i], i});
    }
    long long nowSize = foodSize;
    long long nowTime = 0;
    while(!pq.empty()){
        auto [now, idx] = pq.top();
        now -= nowTime;
        if(k<now*nowSize){
            while(k>=nowSize){
                k-=nowSize;
            }
            for(int i=0; i<foodSize; i++){
                if(food_times[i]==0)    continue;
                if(k==0){
                    return i+1;
                }
                k--;
            }
            break;
        }
        pq.pop();
        food_times[idx] = 0;
        k -= now*nowSize;
        nowSize--;
        nowTime += now;
    }
    return -1;
}