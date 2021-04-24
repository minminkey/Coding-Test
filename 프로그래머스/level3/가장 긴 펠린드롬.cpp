#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int count(int mdx, int pdx, string s){
    int cnt = 0;
    while(1){
        if(mdx<0||pdx>=s.length())  break;
        if(s[mdx]!=s[pdx])  break;
        mdx--;
        pdx++;
        cnt += 2;
    }
    return cnt;
}

int solution(string s)
{
    int answer=0;
    for(int i=0; i<s.length(); i++){
        int cnt = count(i-1, i+1, s) + 1;
        int cnt1 = count(i, i+1, s);
        answer = max(answer, max(cnt, cnt1));
    }
    return answer;
}