#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string s = "";
string numbers;
vector<int> num;
int ck[7];

int findPrimeNumber(int n){
    int tmp = sqrt(n);
    for(int i=2; i<=tmp; i++){
        if(n%i == 0)    return 0;
    }
    return 1;
}
void findNumber(int cnt, int length){
    if(cnt>=length) return;
    for(int i=0; i<length; i++){
        if(ck[i] == 1)  continue;
        ck[i] = 1;
        s += numbers[i];
        num.push_back(stoi(s));
        findNumber(cnt+1, length);
        s.pop_back();
        ck[i] = 0;
    }
}

int solution(string Numbers) {
    numbers = Numbers;
    int answer = 0;
    findNumber(0, numbers.length());
    
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for(int i=0; i<num.size(); i++){
        if(num[i]==0||num[i]==1)    continue;
        answer += findPrimeNumber(num[i]);
    }
    
    return answer;
}