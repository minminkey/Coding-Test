#include <string>
#include <vector>
#include <iostream>

using namespace std;

int friends[1001] = {0,};
int isAB[1001] = {0,};

int solution(vector<int> v1, vector<int> v2, int a, int b) {
    int answer = -1;
    for(int i=0; i<v1.size(); i++){
        friends[v1[i]]++;
        friends[v2[i]]++;
        if(v1[i] == a || v1[i] == b){
            isAB[v2[i]]++;
        }
        if(v2[i] == a || v2[i] == b){
            isAB[v1[i]]++;
        }
    }
    int minFriend = 10000;
    for(int i=0; i<=1000; i++){
        if(isAB[i] == 2){
            if(minFriend > friends[i]){
                minFriend = friends[i];
                answer = i;
            }
        }
    }
    return answer;
}