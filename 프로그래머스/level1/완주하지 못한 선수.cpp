#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> mp;
    for(int i=0; i<participant.size(); i++){
        mp[participant[i]]++;
    }
    for(int i=0; i<completion.size(); i++){
        mp[completion[i]]--;
    }
    for(int i=0; i<participant.size(); i++){
        if(mp[participant[i]]>=1){
            return participant[i];
        }
    }
}