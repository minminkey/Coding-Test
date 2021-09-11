#include <string>
#include <vector>

using namespace std;

int num[11];

int solution(vector<int> numbers) {
    int answer = 0;
    for(int i=0; i<numbers.size(); i++){
        num[numbers[i]]++;
    }
    for(int i=1; i<10; i++){
        if(num[i]==0)   answer+=i;
    }
    return answer;
}