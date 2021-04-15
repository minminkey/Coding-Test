#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool ck(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.empty())              return false;
            char t = st.top();
            st.pop();
            if(s[i]==')'&&t!='(')       return false;
            else if(s[i]=='}'&&t!='{')  return false;
            else if(s[i]==']'&&t!='[')  return false;
        }
    }
    if(!st.empty()) return false;
    return true;
}
//[[]

int solution(string s) {
    int answer = 0;
    for(int x=0; x<s.length(); x++){
        if(ck(s))   answer++;
        char f = s[s.length()-1];
        s = f + s.substr(0, s.length()-1);
    }
    return answer;
}