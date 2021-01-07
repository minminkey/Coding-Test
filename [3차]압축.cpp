#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    int cnt = 27;
    for(int i=0; i<26; i++){
        string tmp = "";
        tmp+='A'+i;
        dic[tmp] = i+1;
    }
    for(int i=0; i<msg.size(); i++){
        string tmp2 = "";
        int idx;
        for(int j=i; j<msg.size(); j++){
            tmp2 += msg[j];
            map<string, int> :: iterator iter;
            iter = dic.find(tmp2);
            int flag = 0;
            if(iter==dic.end()){
                dic[tmp2] = cnt++;
                tmp2= "";
                break;
            }
            else{
                idx = iter->second;
                i = j;
            }
        }
        answer.push_back(idx);
    }
    return answer;
}