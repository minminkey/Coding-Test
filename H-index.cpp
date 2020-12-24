#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    sort(citations.begin(), citations.end());
    for(int i=0; i<=citations[size-1]; i++){
        int h = i;
        int flag = 0;
        for(int j=0; j<size; j++){
            if(citations[j]>=h){
                if(j>size-h){
                    flag = 1;
                    break;
                }
                else{
                    break;
                }
            }
        }
        if(flag==1) break;
        else        answer = h;
    }
    return answer;
}