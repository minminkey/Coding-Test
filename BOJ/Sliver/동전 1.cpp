#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> input;
long long dp[10011];
int n,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        input.push_back(tmp);
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=input[i]; j<=k; j++){
            dp[j] += dp[j-input[i]];
        }
    }
    cout<<dp[k]<<'\n';
	return 0;
}