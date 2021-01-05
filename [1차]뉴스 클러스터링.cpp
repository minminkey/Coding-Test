#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void fregment(string str, vector<string> &s){
    for(int i=0; i<str.length()-1; i++){
        string tmp="";
        if(!isalpha(str[i])||!isalpha(str[i+1]))  continue;
        tmp += tolower(str[i]);
        tmp += tolower(str[i+1]);
        s.push_back(tmp);
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1;
    vector<string> s2;
    fregment(str1, s1);
    fregment(str2, s2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    float Inter = 0;
    float Union = 0;
    for(int i=0; i<s1.size(); i++){
        int num = i;
        int gap;
        for(int j=i+1; j<s1.size(); j++){
            if(s1[i]==s1[j])  num++;
            else                break;
        }
        gap = num - i + 1;
        int flag = 1;
        for(int j=0; j<s2.size(); j++){
            if(s1[i] == s2[j]){
                int num2 = j;
                int gap2;
                for(int k=j+1; k<s2.size(); k++){
                    if(s2[j]==s2[k])    num2++;
                    else                break;
                }
                gap2 = num2 - j + 1;
                Inter += min(gap, gap2);
                Union += max(gap, gap2);
                flag = 0;
                break;
            }
        }
        i = num;
    }
    for(int i=0; i<s2.size(); i++){
        int flag=1;
        for(int j=0; j<s1.size(); j++){
            if(s2[i]==s1[j]){
                flag=0;
                break;
            }
        }
        if(flag)    Union++;
    }
    for(int i=0; i<s1.size(); i++){
        int flag=1;
        for(int j=0; j<s2.size(); j++){
            if(s1[i]==s2[j]){
                flag=0;
                break;
            }
        }
        if(flag)    Union++;
    }
    answer = (Inter/Union)*65536;
    if(s1.size()==0&&s2.size()==0)  return 65536;
    return answer;
}