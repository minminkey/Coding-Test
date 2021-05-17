#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
vector<int> m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    int sum = 0;
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        m.push_back(tmp);
    }
    sort(m.begin(), m.end());
    if(m[0]!=1) cout<<1<<'\n';
    else{
        sum += 1;
        for(int i=1; i<N; i++){
            if(m[i]>sum+1)
                break;
            sum += m[i];
        }
        cout<<sum+1<<'\n';
    }
	return 0;
}