#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[101][101];

string addNum(string a, string b) {
    unsigned long long int sum = 0;
    string ret;
    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()) {
            sum+=a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()) {
            sum+=b.back() - '0';
            b.pop_back();
        }
        ret.push_back((sum%10) + '0');
        sum/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string combination(int n, int r) {
    if(n==r || r==0)
        return "1";
    string &ret = dp[n][r];
    if(ret != "")
        return ret;
    ret=addNum(combination(n-1, r-1), combination(n-1, r));
    return ret;
}
int main() {
    int n,m;
    cin>>n>>m;
    cout<<combination(n,m);
    return 0;
}
