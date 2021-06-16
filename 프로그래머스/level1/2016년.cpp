#include <string>
#include <vector>
#include <iostream>

using namespace std;
int m[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
string solution(int a, int b) {
    string answer = "";
    int day = -1;
    for(int i=1; i<a; i++){
        day += m[i];
    }
    day += b;
    answer = s[day%7];
    cout<<day<<endl;
    return answer;
}