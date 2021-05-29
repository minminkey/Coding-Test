#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> neg;
vector<int> pos;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    long long sum = 0;
    for(int i=0; i<N; i++){
        int tmp;
        cin>>tmp;
        if(tmp==1)  sum+=tmp;
        else if(tmp<=0){
            neg.push_back(tmp);
        }
        else{
            pos.push_back(tmp);
        }
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(), greater<int>());
    for(int i=0; i<neg.size()-1; i+=2){
        if(i+1>=neg.size()) break;
        sum += (neg[i] * neg[i+1]);
    }
    if(neg.size()%2!=0){
        sum += neg[neg.size()-1];
    }
    for(int i=0; i<pos.size()-1; i+=2){
        if(i+1>=pos.size()) break;
        sum += (pos[i] * pos[i+1]);
    }
    if(pos.size()%2!=0){
        sum += pos[pos.size()-1];
    }
    cout<<sum<<'\n';
	return 0;
}