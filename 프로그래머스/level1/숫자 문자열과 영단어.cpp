#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans = "";
    map<string, string> dic;
    dic["zero"] = "0";
    dic["one"] = "1";
    dic["two"] = "2";
    dic["three"] = "3";
    dic["four"] = "4";
    dic["five"] = "5";
    dic["six"] = "6";
    dic["seven"] = "7";
    dic["eight"] = '8';
    dic["nine"] = "9";
    for(int i=0; i<s.length(); i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans += s[i];
            continue;
        }
        if(dic.find(s.substr(i,3))!=dic.end()){
            ans += dic[s.substr(i,3)];
            i += 2;
        }
        else if(dic.find(s.substr(i,4))!=dic.end()){
            ans += dic[s.substr(i,4)];
            i += 3;
        }
        else if(dic.find(s.substr(i,5))!=dic.end()){
            ans += dic[s.substr(i,5)];
            i += 4;
        }
    }
    answer = stoi(ans);
    return answer;
}