#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <string.h>
using namespace std;

char mp[1050][1050];

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int now = 1;
    memset(mp, ' ', sizeof(mp));
    mp[0][0] = '*';
    for(int i=0; i<n; i++){
        for(int r=now; r<2*now; r++){
            for(int c=0; c<now; c++){
                mp[r][c] = mp[r-now][c];
            }
        }
        for(int r=0; r<now; r++){
            for(int c=now; c<2*now; c++){
                mp[r][c] = mp[r][c-now];
            }
        }
        now *=2;
    }
    int k = 0;
    for(int i=0; i<now; i++){
        for(int j=0; j<now-k; j++){
            cout<<mp[i][j];
        }
        k++;
        cout<<endl;
    }
    return 0;
}
