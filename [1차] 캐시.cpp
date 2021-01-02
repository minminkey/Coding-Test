#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;



int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list <string> lt;
    if(cacheSize==0){
        return 5*cities.size();
    }
    for(int i=0; i<cities.size(); i++){
        list<string>::iterator iter;
        int flag = 1;
        for(int j=0; j<cities[i].size(); j++){
            cities[i][j] = tolower(cities[i][j]);
        }
        for(iter = lt.begin(); iter != lt.end(); iter++){
            if(cities[i].compare(*iter)==0){
                lt.remove(cities[i]);
                lt.push_front(cities[i]);
                flag = 0;
                answer++;
                break;
            }
        }
        if(flag){
            if(lt.size()==cacheSize&&lt.size()!=0){
                lt.pop_back();
            }
            lt.push_front(cities[i]);
            answer += 5;
        }
    }
    return answer;
}