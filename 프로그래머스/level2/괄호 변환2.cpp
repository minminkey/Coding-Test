#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Divide(string s){
    if(s == "") return "";
    string u = "";
    string v = "";
    int flag = 0;
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        u += s[i];
        if(s[i] == '('){
            cnt++;
        }
        else{
            cnt--;
            if(cnt<0)   flag = 1;
        }
        if(cnt == 0){
            v = s.substr(i+1);
            break;
        }
    }
    if(flag == 0){
        return u + Divide(v);
    }
    string now = "(";
    now += Divide(v);
    now += ")";
    for(int i=1; i<u.length()-1; i++){
        if(u[i] == '(') now += ")";
        else            now += "(";
    }
    return now;
}

string solution(string p) {
    string answer = Divide(p);
    return answer;
}