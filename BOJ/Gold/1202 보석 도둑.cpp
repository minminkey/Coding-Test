#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<pair<int,int>> j;
priority_queue<int> pq;
vector<int> bag;
int visit[201];
int n, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long ans;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int m,v;
        cin>>m>>v;
        j.push_back({m,v});
    }
    for(int i=0; i<k; i++){
        int c;
        cin>>c;
        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());
    sort(j.begin(), j.end());
    int idx = 0;
    for(int i=0; i<bag.size(); i++){
        while(idx<n&&bag[i]>=j[idx].first){
            pq.push(j[idx++].second);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';
    return 0;
}
