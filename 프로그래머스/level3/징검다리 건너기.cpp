#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int l = 1;
    int r = 0;
    for(int i=0; i<stones.size(); i++){
        r = max(r, stones[i]);
    }
    while(l<=r){
        int cnt = 0;
        int mid = (l+r)/2;
        int flag = 0;
        for(int i=0; i<stones.size(); i++){
            if(stones[i]-mid+1<=0){
                cnt++;
            }
            else    cnt = 0;
            if(cnt>=k){
                flag = 1;
                break;                
            }
        }
        if(flag == 1){
            r = mid-1;
        }
        else{
            l = mid+1;
            answer = mid;
        }
    }
    return answer;
}