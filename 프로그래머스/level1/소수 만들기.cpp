#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector<int> candidate;
int cnt;
int visit[51];

bool find(int x){
    for(int i=2; i<=sqrt(x); i++){
        if(x%i == 0)    return false;
    }
    return true;
}
void dfs(int n, int start, vector<int> nums){
    if(n>=3){
        int sum = 0;
        for(int i=0; i<3; i++){
            sum += candidate[i];
            // cout<<candidate[i]<<' ';
        }
        // cout<<endl<<sum<<endl;
        if(find(sum))   cnt++;
        return;
    }
    for(int i=start; i<nums.size(); i++){
        if(visit[i] == 1)   continue;
        visit[i] = 1;
        candidate.push_back(nums[i]);
        dfs(n+1, i+1, nums);
        candidate.pop_back();
        visit[i] = 0;
    }
}
int solution(vector<int> nums) {
    int answer = -1;
    dfs(0, 0, nums);
    answer = cnt;
    return answer;
}