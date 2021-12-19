#include <string>
#include <vector>

using namespace std;

int user[1001] = {0,};

int solution(vector<vector<int>> lottery) {
    int answer = 0;
    int userCnt = 0;
    int userSum = 0;
    for(int i=0; i<lottery.size(); i++){
        int id = lottery[i][0];
        if(user[id] == -1)  continue;
        user[id]++;
        if(lottery[i][1]){
            userCnt++;
            userSum += user[id];
            user[id] = -1;
        }
    }
    if(userCnt == 0){
        return answer;
    }
    answer = userSum/userCnt;
    return answer;
}