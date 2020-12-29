#include <string>
#include <vector>

using namespace std;
vector<int> number;
int target;
int cnt;
void dfs(int idx, int sum){
    if(idx == number.size()){
        if(sum == target){
            cnt++;
        }
        return;
    }
    dfs(idx+1, sum+number[idx]);
    dfs(idx+1, sum-number[idx]);
}
int solution(vector<int> numbers, int t) {
    int answer = 0;
    target = t;
    number = numbers;
    dfs(0,0);
    return cnt;
}