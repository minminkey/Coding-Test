#include <string>
#include <vector>

using namespace std;

int solution(vector<int> grade) {
    int answer = 0;
    for(int i=grade.size()-2; i>=0; i--){
        if(grade[i+1]<grade[i]){
            answer += grade[i] - grade[i+1];
            grade[i] = grade[i+1];
        }
    }
    return answer;
}