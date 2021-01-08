#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string target = "1";
    int zerocnt = 0;
    int cnt = 0;
    while(!(s.length()==1&&s[0] == '1')){
        string tmp = "";
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1')   tmp += s[i];  
            else            zerocnt++;
        }
        s = "";
        int l = tmp.length();
        while(l!=0){
            s += to_string(l%2);
            l /= 2;
        }
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zerocnt);
    return answer;
}