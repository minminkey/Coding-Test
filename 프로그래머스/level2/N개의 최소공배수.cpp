#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    int tmp = 1;
    while(1){
        int cnt = arr[0]*tmp;
        int flag = 1;
        for(int i=0; i<arr.size(); i++){
            if(cnt%arr[i]!=0){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            return arr[0]*tmp;
        }
        else{
            tmp++;
        }
    }
    return answer;
}