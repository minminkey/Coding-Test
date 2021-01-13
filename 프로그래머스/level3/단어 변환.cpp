#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visit[51];
int Min = 100;

void dfs(vector<string> words, string begin, string target, int cnt){
    for(int i=0; i<words.size(); i++){
        if(visit[i]==1) continue;
        int tmp = 0;
        for(int j=0; j<begin.size(); j++){
            if(begin[j] == words[i][j]) continue;
            tmp++;
            if(tmp>1)   break;
        }
        if(tmp==1){
            if(target.compare(words[i])==0){
                Min = min(Min, cnt);
                return;
            }
            visit[i] = 1;
            dfs(words, words[i], target, cnt+1);
            visit[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dfs(words, begin, target, 1);
    if(Min == 100)   return 0;
    return Min;
}