#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    for(int i=0; i<operations.size(); i++){
        char flag = operations[i][0];
        int flag2 = stoi(operations[i].substr(2));
        // cout<<flag<<' '<<flag2<<endl;
        if(flag == 'I'){
            ms.insert(flag2);
        }
        else if(flag == 'D'){
            if(flag2==1&&ms.size()>0){
                ms.erase(--ms.end());
            }
            else{
                if(ms.size()>0){
                    ms.erase(ms.begin());
                }
            }
        }
    }
    if(ms.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
    return answer;
}