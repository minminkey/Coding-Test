#include <iostream>
#include <stack>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<int> st;
    for(int i=0; i<s.length(); i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            if(st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    if(st.size()==0)    answer = 1;
    return answer;
}