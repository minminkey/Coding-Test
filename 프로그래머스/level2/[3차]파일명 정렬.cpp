#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Files{
    string head;
    string tail;
    int idx;
    int num;
};
bool cmp(const struct Files &a, const struct Files &b){
    if(a.head.compare(b.head)==0){
        if(a.num==b.num)    return a.idx < b.idx;
        return a.num < b.num;
    }
    else{
        return a.head < b.head;
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<struct Files> f;
    for(int i=0; i<files.size(); i++){
        struct Files tmp;
        tmp.head = "";
        tmp.tail = "";
        tmp.idx = i;
        string tnum = "";
        int flag = 1;
        for(int j=0; j<files[i].size(); j++){
            char tc = files[i][j];
            if(files[i][j]>='A'&&files[i][j]<='Z'){
                tc = tolower(files[i][j]);
            }
            if(tc>='0'&&tc<='9'&&flag==1){
                tnum += tc;
                for(int k=j+1; k<files[i].size(); k++){
                    if(files[i][k]>='0'&&files[i][k]<='9'){
                        tnum += files[i][k];
                        j=k;
                    }
                    else    break;
                }
                tmp.num = stoi(tnum);
                tmp.tail = files[i].substr(j+1);
                break;
            }
            else{
                tmp.head += tc;
            }
        }
        f.push_back(tmp);
    }
    sort(f.begin(), f.end(), cmp);
    for(int i=0; i<f.size(); i++){
        answer.push_back(files[f[i].idx]);
    }
    return answer;
}