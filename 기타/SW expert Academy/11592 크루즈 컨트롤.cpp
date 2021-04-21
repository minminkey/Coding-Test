#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    int TC;
    cin>>TC;
    for(int t=1; t<=TC; t++){
        int d, n;
        cin>>d>>n;
        double time = 0;
        for(int i=0; i<n; i++){
            int k, s;
            cin>>k>>s;
            double tmp = (double)(d - k)/(double)s;
            time = max(time, tmp);
        }
        double ans = (double)d/time;
        printf("#%d %.7lf\n",t, ans);
    }
	return 0;
}