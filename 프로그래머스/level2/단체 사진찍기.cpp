#include <string>
#include <vector>

using namespace std;

bool visit[8];
char kakao[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
int CNT = 0;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
void dfs(int cnt, char arr[], vector<string> data){
    if(cnt==8){
        for(int i=0; i<data.size(); i++){
            char tmp1 = data[i][0];
            char tmp2 = data[i][2];
            char cond = data[i][3];
            int count = data[i][4] - '0';
            count++;
            int idx1 = -1;
            int idx2 = -1;
            for(int j=0; j<8; j++){
                if(arr[j]==tmp1)    idx1 = j;
                if(arr[j]==tmp2)    idx2 = j;
                if(idx1!=-1&&idx2!=-1)  break;
            }
            if(cond=='='&&abs(idx1-idx2)!=count)    return;
            if(cond=='>'&&abs(idx1-idx2)<=count)    return;
            if(cond=='<'&&abs(idx1-idx2)>=count)    return;
        }
        CNT++;
        return;
    }
    for(int i=0; i<8; i++){
        if(visit[i]==true)  continue;
        visit[i]=true;
        arr[cnt] = kakao[i];
        dfs(cnt+1, arr, data);
        visit[i]=false;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    CNT = 0;
    char arr[8] = {NULL, };
    dfs(0, arr, data);
    answer = CNT;
    return answer;
}