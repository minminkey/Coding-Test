#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> dice;
int number[10001];

void dfs(vector<int> visit, int cnt, string now, int want){
    // cout<<cnt<<' '<<now<<' '<<want<<endl;
    // if(cnt==1)  return;
    if(now.length() == want){
        int res = stoi(now);
        number[res]++;
        return;
    }
    for(int i=0; i<dice.size(); i++){
        if(visit[i] == 1)   continue;
        visit[i] = 1;
        for(int j=0; j<dice[i].size(); j++){
            string next = to_string(dice[i][j]);
            dfs(visit, cnt+1, now+next, want);
        }
        visit[i] = 0;
    }
}

int solution(vector<vector<int>> Dice) {
    int answer = 0;
    dice = Dice;
    vector<int> visit;
    for(int i=0; i<=dice.size(); i++){
        visit.push_back(0);
    }
    for(int i=0; i<dice.size(); i++){
        dfs(visit, 0, "", i+1);
    }
    for(int i=1; i<10000; i++){
        if(number[i]==0)    return i;
    }
    return answer;
}