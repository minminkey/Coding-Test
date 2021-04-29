#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

map<long long, long long> mp;

long long Find(long long now){
    if(mp.find(now)==mp.end()){
        mp[now] = now + 1;
        return now+1;
    }
    return mp[now] = Find(mp[now]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0; i<room_number.size(); i++){
        long long want = room_number[i];
        long long f = Find(want);
        answer.push_back(f-1);
    }
    return answer;
}