#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long flag = 10000000000;
string ans;

string oper[2] = {"*", "+"};
vector<string> a;
//dfs
void dfs(long long now, long long t, string op){
    if(flag<op.length()) return;
    if(now==t){
        if(flag>=op.length()){
            // ans = op;
            a.push_back(op);
            flag = op.length();
        }
        return;
    }
    if(now>t)   return;
    for(int i=0; i<2; i++){
        if(i==0 && now != 1) 
            dfs(now * now, t, op+oper[i]);
        else if(i == 1)
            dfs(now + now, t, op+oper[i]);
    }
}
bool cmp(string a, string b){
    if(a.length()==b.length())  return a<b;
    return a.length()<b.length();
}
int main(){
    int s, t;
    cin>>s>>t;
    if(s==t){
        cout<<0<<"\n";
        return 0;
    }
    if(s==0){
        cout<<-1<<"\n";
        return 0;
    }
    else if(t==0){
        cout<<"-"<<"\n";
        return 0;
    }
    if(s!=1)    dfs(1, t, "/");
    dfs(s, t, "");
    if(a.size() == 0){
        cout<<-1<<"\n";
        return 0;
    }
    sort(a.begin(), a.end(), cmp);
    cout<<a[0]<<"\n";
    return 0;
}