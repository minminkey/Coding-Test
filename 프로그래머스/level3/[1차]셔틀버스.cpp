#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    int answer = -100;
    string ans = "";
    int flag = 1;
    vector<int> time;
    for(int i=0; i<timetable.size(); i++){
        int hours = stoi(timetable[i].substr(0,2));
        int minutes = stoi(timetable[i].substr(3,2));
        time.push_back(hours*60+minutes);
    }
    sort(time.begin(), time.end());
    int nextArrive = 540;
    int nowIdx = 0;
    for(int i=0; i<n; i++){
        int full = m;
        for(int j=nowIdx; j<time.size(); j++){
            if(time[j]<=nextArrive){
                nowIdx++;
                full--;
                if(full==0) break;
            }
        }
        if(i+1==n){
            if(full==0){
                answer = time[nowIdx-1]-1;
            }
            else{
                answer = nextArrive;
            }
        }
        nextArrive += t;
        
    }
    string h = to_string(answer/60);
    string mi = to_string(answer%60);
    if(answer/60<10){
        h = "0"+h;
    }
    if(answer%60<10){
        mi = "0"+mi;
    }
    ans += h;
    ans += ":";
    ans += mi;
    return ans;
}