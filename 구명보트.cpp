#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int idx = 0;
    int j;
    for(j = people.size()-1; j>idx; j--){
        if(people[j]+people[idx]<=limit){
            idx++;
            answer++;
        }
        else{
            answer++;
        }
    }
    if(j==idx)  answer++;
    
    return answer;
}