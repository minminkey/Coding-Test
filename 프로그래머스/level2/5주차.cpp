#include <string>
#include <vector>
#include <map>
using namespace std;

int idx = 0;
string arr[5] = {"A", "E", "I", "O", "U"};
map<string, int> res;

void dfs(string now, int cnt){
    if(cnt>5)   return;
    res[now] = idx++;
    for(int i=0; i<5; i++){
        string next = now + arr[i];
        dfs(next, cnt+1);
    }
}

int solution(string word) {
    int answer = 0;
    dfs("", 0);
    answer = res[word];
    return answer;
}