#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, string> parent;
    map<string, int> profit;
    parent["-"] = "--";
    profit["-"] = 0;
    for(int i=0; i<enroll.size(); i++){
        parent[enroll[i]] = referral[i];
        profit[enroll[i]] = 0;
    }
    for(int i=0; i<seller.size(); i++){
        string Child = seller[i];
        string Parent = parent[Child];
        int pro = amount[i] * 100;
        while(1){
            int ppro = floor((double)pro*0.1);
            if(Parent=="--"||ppro<1){
                profit[Child] += pro;
                break;
            }
            profit[Child] += pro - ppro;            
            pro = ppro;
            Child = Parent;
            Parent = parent[Child];
        }
    }
    for(int i=0; i<enroll.size(); i++){
        answer.push_back(profit[enroll[i]]);
    }
    return answer;
}