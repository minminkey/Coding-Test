#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
string Change(string m){
    string tmp ="";
    for(int i=0; i<m.length()-1; i++){
        if(m[i+1]=='#'){
            tmp += m[i]+32;
            i++;
        }
        else{
            tmp += m[i];
        }
    }
    if(m[m.size()-1]!='#'){
        tmp+=m[m.size()-1];
    }
    return tmp;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    m = Change(m);
    int Max = -1;
    
    for(int i=0; i<musicinfos.size(); i++){
        int sh = stoi(musicinfos[i].substr(0,2));
        int sm = stoi(musicinfos[i].substr(3,2));
        int eh = stoi(musicinfos[i].substr(6,2));
        int em = stoi(musicinfos[i].substr(9,2));
        int time = (60*eh+em)-(60*sh+sm);
        string name = "";
        string music = "";
        string t = "";
        for(int j=12; j<musicinfos[i].size(); j++){
            if(musicinfos[i][j]==','){
                name = musicinfos[i].substr(12,j-12);
                t = musicinfos[i].substr(j+1);
                break;
            }
        }
        music = Change(t);
        if(music.size()<time){
            string tmp = music;
            int t = time-music.size();
            for(int j=0; j<t; j++){
                music += tmp[j%tmp.size()];
            }
        }            
        else{
            music = music.substr(0, time);
        }
        if(music.find(m)!=string::npos){
            if(Max<time){
                Max = time;
                answer = name;
            }
        }
    }
    return answer;
}