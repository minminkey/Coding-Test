#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int e = 0;
    int o = 0;
    for(int i=left; i<=right; i++){
        int cnt = 0;
        for(int num=1; num<=i; num++){
            if(i%num==0)    cnt++;
        }
        if(cnt%2==0)    answer += i;
        else            answer -= i;
    }
    return answer;
}