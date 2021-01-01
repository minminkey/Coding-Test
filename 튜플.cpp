#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tmp;
    vector<vector<int>> numbers;
    string number = "";
    for(int i=1; i<s.length()-1; i++){
        if(s[i]=='{'){
            tmp.clear();
        }
        else if(s[i]=='}'){
            tmp.push_back(stoi(number));
            numbers.push_back(tmp);
            number = "";
        }
        else if(s[i]==','){
            if(number != ""){
                tmp.push_back(stoi(number));
                number = "";
            }
        }
        else{
            number += s[i];
        }
    }
    sort(numbers.begin(), numbers.end(), cmp);
    for(int i=0; i<numbers.size(); i++){
        for(int j=0; j<numbers[i].size(); j++){
            int flag = 1;
            for(int k=0; k<answer.size(); k++){
                if(answer[k]==numbers[i][j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                answer.push_back(numbers[i][j]);
                break;
            }
        }
    }
    return answer;
}