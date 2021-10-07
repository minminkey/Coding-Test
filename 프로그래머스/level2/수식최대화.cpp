//구현
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char order[][3] = {
    {'+', '-', '*'},
    {'+', '*', '-'},
    {'-', '+', '*'},
    {'-', '*', '+'},
    {'*', '+', '-'},
    {'*', '-', '+'}
};

long long exp(long long a, long long b, string ex){
    if(ex == "+")       return a+b;
    else if(ex == "-")  return a-b;
    else if(ex == "*")  return a*b;
}

long long solution(string expression) {
    long long answer = 0;
    string word = "";
    vector<string> copy;
    for(int i=0; i<expression.length(); i++){
        if(expression[i]>='0'&&expression[i]<='9'){
            word += expression[i];
        }
        else{
            copy.push_back(word);
            string f = "";
            f += expression[i];
            copy.push_back(f);
            word = "";
        }
    }
    copy.push_back(word);
    for(int i=0; i<6; i++){
        vector<string> list = copy;
        for(int j=0; j<3; j++){
            vector<string> tmp;
            string target = "";
            target += order[i][j];
            for(int k=0; k<list.size(); k++){
                if(list[k] == target){
                    long long a = stoll(tmp[tmp.size()-1]);
                    long long b = stoll(list[k+1]);
                    long long res = exp(a, b, list[k]);
                    tmp.pop_back();
                    tmp.push_back(to_string(res));
                    k++;
                }
                else{
                    tmp.push_back(list[k]);
                }
            }
            list = tmp;
        }
        answer = max(answer, abs(stoll(list[0])));
    }
    return answer;
}