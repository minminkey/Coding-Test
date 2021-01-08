#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int flag = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            flag = 0;
        }
        else if(flag == 0){
            if(s[i]>='a' && s[i]<='z'){
                s[i] -= 32;
            }
            flag++;
        }
        else{
            if(s[i]>='A' && s[i]<='Z'){
                s[i] += 32;
            }
            flag++;
        }
    }
    return s;
}