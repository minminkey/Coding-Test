#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    int ans;
    cin>>n>>k;
    int s = 1;
    int e = k;
    int mid;
    while(s<=e){
        mid = (s+e)/2;
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += min(n, mid/i);
        }
        if(sum>=k){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    cout<<ans<<'\n';
}