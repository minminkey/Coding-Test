#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int cnt = right - left + 1;
    int sRow = left/n;
    int remain = left%n;
    int eRow = right/n;
    for(int r=sRow; r<=eRow; r++){
        int now = r+1;
        int tcnt = 0;
        int rcnt = 0;
        // cout<<now<<endl;
        for(int c=0; c<n; c++){
            tcnt++;
            if(tcnt>r+1){
                now++;
            }
            // cout<<r<<' '<<tcnt<<' '<<now<<endl;
            if(r == sRow){
                rcnt++;
                if(rcnt<=remain) continue;
            }
            cnt--;
            answer.push_back(now);
            if(cnt == 0)    return answer;
        }
    }
    return answer;
}