#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int num = n;
    while(num!=0){
        int x = num%3;
        num = num/3;
        if(x == 0){
            num -= 1;
            answer.insert(0,"4");
        }
        else{
            answer.insert(0,to_string(x));
        }
    }
    return answer;
}