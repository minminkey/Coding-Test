#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int arr[101][101];
string dp[101][101];

string bigInteger(string n, string m) {
    string ans = "";
    if (n.length() < m.length()) swap(n, m);
    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());
    int a = 0, b = 0, carry = 0;
    for (int i = 0; i < n.length(); i++) {
        a = n[i] - 48;
        b = i < m.length() ? m[i] - 48 : 0;
        ans += (a + b + carry) % 10 + 48;
        carry = (a + b + carry) / 10;
        if (carry == 1 && i == (n.length() - 1)) {
            ans += '1';
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            dp[i][j] = "0";
        }
    }
    
    dp[0][0] = "1";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j]=="0"||arr[i][j]==0) continue;
            int d = arr[i][j];
            if(i+d<n){
                dp[i+d][j] = bigInteger(dp[i+d][j], dp[i][j]);
            }
            if(j+d<n){
                dp[i][j+d] = bigInteger(dp[i][j+d], dp[i][j]);
            }
        }
    }
    cout<<dp[n-1][n-1]<<"\n";
    return 0;
}