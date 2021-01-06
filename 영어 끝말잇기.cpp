#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<int> part;
    vector<string> tmp;
    int turn = 1;
    int cnt = 2;
    for(int i=1; i<=n; i++){
        part.push_back(0);
    }
    tmp.push_back(words[0]);
    for(int i=1; i<words.size(); i++){
        string prev = tmp.back();
        if(prev[prev.length()-1] != words[i][0]){
            answer.push_back(cnt);
            answer.push_back(turn);
            return answer;
        }
        else{
            if(find(tmp.begin(), tmp.end(), words[i])==tmp.end()){
                if(words[i].compare(tmp.back())==0){
                    answer.push_back(cnt);
                    answer.push_back(turn);
                    return answer;
                }
            }
            else{
                answer.push_back(cnt);
                answer.push_back(turn);
                return answer;
            }
            tmp.push_back(words[i]);
        }
        cnt++;
        if(cnt>n){
            turn++;
            cnt = 1;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}