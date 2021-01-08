#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(')    cnt++;
        else               cnt--;
        if(cnt<0)   return false;
    }
    if(cnt!=0)  return false;
    return answer;
}