#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int n, k;
int device[101];
int in[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin>>n>>k;
    for(int i=0; i<k; i++){
        cin>>device[i];
    }
    int cnt = 0;
    for(int i=0; i<k; i++){
        int now = device[i];
        // cout<<now<<endl;
        if(in[now]==1)  continue;
        if(cnt<n){
            in[now] = 1;
            cnt++;
            continue;
        }
        int maxIdx = 0;
        int target = -1;
        // cout<<"start "<<now<<endl;
        for(int idx=1; idx<=k; idx++){
            // cout<<in[idx]<<' ';
            if(in[idx]==0)  continue;
            // cout<<"find "<<idx<<endl;
            int flag = 0;
            for(int j = i+1; j<k; j++){
                if(idx == device[j]){
                    // cout<<idx<<' '<<j<<endl;
                    if(maxIdx<j){
                        maxIdx = j;
                        target = idx;
                    }
                    flag = 1;
                    break;
                }
            }
            // cout<<target<<endl;
            if(flag==0){
                target = idx;
                break;
            }
        }
        in[target] = 0;
        in[now] = 1;
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
