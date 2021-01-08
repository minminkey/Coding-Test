#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    int l = name.length();
    int tmp = 0;
    int turn = l - 1;
    for(int i=0; i<l; i++){
        tmp += min(name[i] - 'A', 'Z' - name[i] + 1);
        int next = i+1;
        while(next<l&&name[next]=='A') next++;
        turn = min(turn, i+l-next+min(i, l-next));
    }
    answer += turn;
    answer += tmp;
    return answer;
}