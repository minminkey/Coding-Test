#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

vector<int> point;
int G, P;

int findNext(int now){
    if(point[now]==now){
        point[now] = now-1;
        return now;
    }
    return point[now] = findNext(point[now]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>G>>P;
    int flag = 0;
    int cnt = 0;
    for(int i=0; i<=G; i++){
        point.push_back(i);
    }
    for(int i=0; i<P; i++){
        int in;
        cin>>in;
        if(flag == 1)   continue;
        int next = findNext(in);
        // cout<<next<<endl;
        if(next == 0){
            flag = 1;
        }
        else{
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
