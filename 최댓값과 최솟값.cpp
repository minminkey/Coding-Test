#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    vector <int> str;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            str.push_back(stoi(tmp));
            tmp = "";
        }
        else{
            tmp += s[i];
        }
    }
    str.push_back(stoi(tmp));
    sort(str.begin(), str.end());
    answer += to_string(str[0]);
    answer += ' ';
    answer += to_string(str[str.size()-1]);
    return answer;
}