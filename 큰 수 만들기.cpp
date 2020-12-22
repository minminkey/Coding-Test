#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = -1;
    for(int i=0; i<number.size()-k; i++){
        char max = 0;
        for(int j = idx+1; j<=k+i; j++){
            if(max<number[j]){
                idx = j;
                max = number[j];
            }
        }
        answer += max;
    }
    return answer;
}