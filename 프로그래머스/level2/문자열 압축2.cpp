#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Cut(int num, string s){
    vector<string> str;
    for(int i=0; i<s.length(); i+=num){
        str.push_back(s.substr(i, num));
    }
    string now = "";
    string prev = "";
    int cnt = 0;
    for(int i=0; i<str.size(); i++){
        if(prev == str[i]){
            cnt++;
        }
        else{
            if(cnt > 1){
                now += to_string(cnt);
            }
            cnt = 1;
            prev = str[i];
            now += str[i];
        }
    }
    if(cnt>1){
        now += to_string(cnt);
    }
    return now.length();
}

int solution(string s) {
    int answer = 1001;
    for(int i=1; i<=s.length()/2+1; i++){
        answer = min(answer, Cut(i, s));
    }
    return answer;
}