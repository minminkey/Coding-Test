#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int n, m;
int ck[1001] = {0, };

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        vector<pair<int, int>> want;
        memset(ck, 0, sizeof(ck));
        int ans = 0;
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            want.push_back({a,b});
        }
        sort(want.begin(), want.end(), cmp);
        for(int i=0; i<want.size(); i++){
            auto[a, b] = want[i];
            for(int j=a; j<=b; j++){
                if(ck[j]==0){
                    ck[j] = 1;
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
