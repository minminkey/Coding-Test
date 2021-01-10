#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> group;
vector<bool> rule1;
vector<bool> rule2;
vector<bool> used;
int idx;
int flag;

struct info{
    int start, end, cnt;
};

bool ck_rule1(string& sentence, info s_info, char c){
    if(used[c-'a']==true)  return false;
    if(s_info.start-1 < 0 || s_info.end+1 >= N) return false;
    if(islower(sentence[s_info.start-1])||islower(sentence[s_info.end+1]))  return false;
    int lcnt = 0;
    int ucnt = 0;
    for(int i=s_info.start-1; i<=s_info.end+1; ++i){
        char now = sentence[i];
        if(islower(now)){
            if(now==c){
                group[i] = idx;
                lcnt++;
                ucnt = 0;
            }
            else return false;
        }
        else if(isupper(now)){
            lcnt = 0;
            ucnt++;
            if(rule1[i]==true)  return false;
            else{
                group[i] = idx;
                rule1[i] = true;
            }
        }
        if(lcnt>1||ucnt>1)  return false;
    }
    idx++;
    used[c - 'a'] = true;
    return true;
}
bool ck_rule2(string& sentence, info s_info, char c){
    if(used[c-'a']) return false;
    if(s_info.end - s_info.start < 2)   return false;
    group[s_info.start] = idx;
    group[s_info.end] = idx;
    for(int i=s_info.start+1; i<s_info.end; ++i){
        char now = sentence[i];
        if(isupper(now)){
            if(rule2[i]==true)    return false;
            else{
                group[i] = idx;
                rule2[i] = true;
            }
        }
    }
    idx++;
    used[c-'a'] = true;
    return true;
}
info getInfo(string& sentence, char c){
    int start = -1;
    int cnt = 0;
    int end = 0;
    for(int i=0; i<N; i++){
        if(sentence[i]==c){
            if(start < 0)   start = i;
            cnt++;
            end = i;
        }
    }
    return {start, end, cnt};
}
bool possible(string &sentence){
    for(int i=0; i<N; i++){
        char now  = sentence[i];
        if(now == ' '){
            flag = 1;
            return false;
        }
        if(group[i]==0){
            if(isupper(now)){
                if(i+1>=N){
                    group[i] = idx++;
                    continue;
                }
                char next = sentence[i+1];
                if(isupper(next)){
                    group[i] = idx++;
                }
                else if(islower(next)){
                    info s_info = getInfo(sentence, next);
                    if(s_info.cnt == 2){
                        group[i] = idx++;
                    }
                    else{
                        if(ck_rule1(sentence, s_info, next)==false){
                            flag = 2;
                            return false;
                        }
                    }
                }
            }
            else if(islower(now)){
                info s_info = getInfo(sentence, now);
                if(s_info.cnt == 2){
                    if(isupper(sentence[i+1])&&rule2[i+1]){
                        if(ck_rule1(sentence, s_info, now)==false){
                            flag = 3;
                            return false;
                        }
                    }
                    else{
                        if(ck_rule2(sentence, s_info, now)==false){
                            flag = 4;
                            return false;
                        }
                    }
                }
                else{
                    if(ck_rule1(sentence, s_info, now)==false){
                        flag = 5;
                        return false;
                    }
                }
            }
        }
        
    }
    return true;
}
string answer(string& sentence){
    int lidx = 0;
    for(int i=0; i<N; i++){
        if(isupper(sentence[i])){
            lidx = group[i];
            break;
        }
    }
    string tmp = "";
    for(int i=0; i<N; i++){
        char c = sentence[i];
        if(isupper(c)){
            if(group[i] != lidx)    tmp += ' ';
            tmp += c;
            lidx = group[i];
        }
    }
    return tmp;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    flag = 0;
    N = sentence.size();
    group = vector<int>(N);
    rule1 = vector<bool>(N);
    rule2 = vector<bool>(N);
    used = vector<bool>(26);
    idx = 1;
    bool result = possible(sentence);
    // cout<<flag<<endl;
    if(!result)     return "invalid";
    return answer(sentence);
}