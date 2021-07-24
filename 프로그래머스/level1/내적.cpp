#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int tmp;
    for(int i=0; i<a.size(); i++){
        tmp = a[i] * b[i];
        answer += tmp;
    }
    
    return answer;
}