#include <iostream>
using namespace std;

int dp[31];

int main(){
    int D, K;
    cin>>D>>K;
    for(int i=1; i<100000; i++){
        for(int j=i+1; j<100000; j++){
            int flag = 0;
            dp[1] = i;
            dp[2] = j;
            for(int k=3; k<=D; k++){
                dp[k] = dp[k-1] + dp[k-2];
                if(dp[k]>K){
                    flag = 1;
                    break;
                } 
            }
            if(flag==0&&dp[D]==K){
                cout<<i<<'\n'<<j;
                return 0;
            }
        }
    }
}
