#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0; i<numbers.size(); i++){
        vector<int> now;
        long long num = numbers[i];
        int cnt=0;
        while(1){
            if(num%2==1)    cnt++;
            else            break;
            num /= 2;
        }
        if(cnt>=2){
            long long tmp = 1;
            for(int j=0; j<cnt-1; j++){
                tmp *= 2;
            }
            answer.push_back(numbers[i]+tmp);
        }
        else{
            answer.push_back(numbers[i]+1);
        }
    }
    return answer;
}