#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i=begin; i<=end; i++){
        if(i==1){
            answer.push_back(0);
            continue;
        }
        long long now = i;
        int flag = 0;
        for(int k=2; k*k<=i; k++){
            if(i%k==0&&i/k<=10000000){
                flag = 1;
                answer.push_back(i/k);
                break;
            }
        }
        if(flag == 0)   answer.push_back(1);
    }
    return answer;
}