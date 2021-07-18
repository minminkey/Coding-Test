#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int value;
    int up;
    int down;
    bool live;
};

Node node[1000001];
stack<int> deleted;

int Up(int start, int cnt){
    int now = start;
    while(cnt>0){
        cnt--;
        now = node[now].up;
    }
    return now;
}

int Down(int start, int cnt){
    int now = start;
    while(cnt>0){
        cnt--;
        now = node[now].down;
    }
    return now;
}

int Delete(int target){
    int upNode = node[target].up;
    int downNode = node[target].down;
    node[target].live = false;
    deleted.push(target);
    if(upNode!=-1)
        node[upNode].down = downNode;
    if(downNode!=-1){
        node[downNode].up = upNode;
        return downNode;
    }
    return upNode;
}

void Recovery(){
    int target = deleted.top();
    deleted.pop();
    node[target].live = true;
    int upNode = node[target].up;
    int downNode = node[target].down;
    if(upNode != -1)
        node[upNode].down = target;
    if(downNode != -1)
        node[downNode].up = target;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int now = k;
    for(int i=0; i<n; i++){
        node[i].value = i;
        node[i].up = i-1;
        node[i].down = i+1;
        node[i].live = true;
    }
    node[n-1].down = -1;
    for(int i=0; i<cmd.size(); i++){
        if(cmd[i][0] == 'U'){
            int cnt = stoi(cmd[i].substr(2));
            now = Up(now, cnt);
        }
        else if(cmd[i][0] == 'D'){
            int cnt = stoi(cmd[i].substr(2));
            now = Down(now, cnt);
        }
        else if(cmd[i][0] == 'C'){
            now = Delete(now);
        }
        else{
            Recovery();
        }
    }
    for(int i=0; i<n; i++){
        if(node[i].live)    answer += "O";
        else                answer += "X";
    }
    return answer;
}