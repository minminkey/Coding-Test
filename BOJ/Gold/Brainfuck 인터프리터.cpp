#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

struct test{
    int sm, sc, si;
    string input, s;
};
struct test testcase[25];

int main(){
    int t;
    vector<string> answer;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>testcase[i].sm>>testcase[i].sc>>testcase[i].si>>testcase[i].input>>testcase[i].s;
    }
    for(int k=0; k<t; k++){
        string ans = "";
        int sm, sc, si;
        string input, s;
        sm=testcase[k].sm;
        sc=testcase[k].sc;
        si=testcase[k].si;
        input=testcase[k].input;
        s=testcase[k].s;
        int p = 0;
        long long cnt = 0;
        int loopS, loopE;
        int flag = 0;
        int mem[100001] = {0, };
        int match[100001] = {0, };
        long long ck[100001] = {0, };
        int sIndex = 0;
        stack<int> st;
        for(int i=0; i<input.length(); i++){
            if(input[i]=='['){
                st.push(i);
            }
            if(input[i]==']'){
                int tmp = st.top();
                match[tmp] = i;
                match[i] = tmp;
                st.pop();
            }
        }
        for(int i=0; i<input.length(); i++){
            if(input[i]=='+'){
                mem[p] = (mem[p]+1)%256;
            }
            else if(input[i]=='-'){
                mem[p]--;
                if(mem[p]==-1)  mem[p] = 255;
            }
            else if(input[i]=='<'){
                if(p==0)    p = sm-1;
                else        p--;
            }
            else if(input[i]=='>'){
                p = (p+1)%sm;
            }
            else if(input[i]=='['){
                if(ck[i] == 0)  ck[i] = cnt;
                if(mem[p]==0){
                    i = match[i];
                    ck[i] = 0;
                }
            }
            else if(input[i]==']'){
                if(mem[p]!=0){
                    i = match[i];
                    if(cnt+1-ck[i]>=50000000){
                        flag = 1;
                        loopS = i;
                        loopE = match[i];
                        break;
                    }
                }
                else{
                    ck[match[i]] = 0;
                }
            }
            else if(input[i]==','){
                if(sIndex==s.length()){
                    mem[p] = 255;
                }
                else{
                    mem[p] = s[sIndex];
                    sIndex++;
                }
            }
            cnt++;
        }
        if(flag==1){
            ans = "Loops " + to_string(loopS) + " " + to_string(loopE);
        }
        else{
            ans = "Terminates";
        }
        answer.push_back(ans);
    }
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<'\n';
    }
}