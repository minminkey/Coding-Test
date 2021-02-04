#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int idx = 0;
    for(int i=0; i<A.size(); i++){
        for(int j=idx; j<B.size(); j++){
            if(A[i]<B[j]){
                answer++;
                idx = j+1;
                break;
            }
        }
    }
    return answer;
}