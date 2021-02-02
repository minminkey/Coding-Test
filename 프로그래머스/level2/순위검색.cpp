#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

map<string, vector<int>> mp;

vector<string> divide(string s){
    string word = "";
    vector<string> entity;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            entity.push_back(word);
            word = "";
        }
        else{
            word += s[i];
        }
    }
    entity.push_back(word);
    return entity;
}
string find_now(string tmp){
    string now;
    if(tmp[0]=='c')       now = "1";
    else if(tmp[0]=='j')  now = "2";
    else if(tmp.compare("python")==0)  now = "3";
    else if(tmp[0]=='b')  now = "1";
    else if(tmp[0]=='f')  now = "2";
    else if(tmp[0]=='s')  now = "1";
    else if(tmp[0]=='j')  now = "2";
    else if(tmp[0]=='p')  now = "2";
    else if(tmp[0]=='a')  now = "";
    else                        now = "0";
    return now;
}
void classfy(string info){
    vector<string> entity;
    entity = divide(info);
    int value = stoi(entity[entity.size()-1]);
    entity.pop_back();
    vector<string> input;
    input.push_back("");
    for(int i=0; i<entity.size(); i++){
        string now = "";
        vector<string> tmp;
        now = find_now(entity[i]);
        for(int j=0; j<input.size(); j++){
            tmp.push_back(input[j]+now);
            tmp.push_back(input[j]+"0");
        }
        input = tmp;
    }
    for(int i=0; i<input.size(); i++){
        mp[input[i]].push_back(value);
    }
}
void find(string query, vector<int> &answer){
    vector<string> entity;
    entity = divide(query);
    int value = stoi(entity[entity.size()-1]);
    entity.pop_back();
    string now = "";
    for(int i=0; i<entity.size(); i++){
        now += find_now(entity[i]);
    }
    int s = 0;
    int e = mp[now].size()-1;
    int target=mp[now].size();
    while(s<=e){
        int mid = (s+e)/2;
        if(mp[now][mid]>=value){
            e = mid-1;
            target = mid;
        }
        else    s = mid+1;
    }
    answer.push_back(mp[now].size()-target);
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i=0; i<info.size(); i++){
        classfy(info[i]);
    }
    map<string, vector<int>> ::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++){
        sort((*it).second.begin(), (*it).second.end());
    }
    for(int i=0; i<query.size(); i++){
        find(query[i], answer);
    }
    return answer;
}