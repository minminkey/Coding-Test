#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <string.h>
using namespace std;

int n, C, m;
int info[2001];
vector<tuple<int, int, int>> box;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    auto [aa, ab, ac] = a;
    auto [ba, bb, bc] = b;
    if(ab==bb){
        if(aa==ba){
            return ac < bc;
        }
        return aa < ba;
    }
    return ab < bb;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>C>>m;
    int ans = 0;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        box.push_back({a,b,c});
    }
    sort(box.begin(), box.end(), cmp);
    for(int i=0; i<box.size(); i++){
        int now = 0;
        auto [a, b, c] = box[i];
        for(int j=a; j<b; j++){
            now = max(now, info[j]);
        }
        int go = min(C-now, c);
        ans += go;
        for(int j=a; j<b; j++){
            info[j] += go;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
