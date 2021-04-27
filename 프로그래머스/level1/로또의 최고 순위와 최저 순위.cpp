#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    int zcnt = 0;
    for(int i=0; i<lottos.size(); i++){
        if(lottos[i]==0){
            zcnt++;
            continue;
        }
        for(int j=0; j<win_nums.size(); j++){
            if(lottos[i]==win_nums[j]){
                cnt++;
                break;
            }
        }
    }
    int best = cnt+zcnt;
    if(best<2)  best = 1;
    else if(best>6) best = 6;
    answer.push_back(7-best);
    int worst = cnt;
    if(worst<2) worst = 1;
    answer.push_back(7-worst);
    return answer;
}