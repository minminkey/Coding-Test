#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <string.h>
using namespace std;

int arr[] = {1,2,3,4,5,6,7};
int ck[100];
vector<int> ans;
int n, k;

void com(int now){
    if(ans.size()==k){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=now; i<n; i++){
        ans.push_back(arr[i]);
        com(i+1);
        // com(i);         //중복 조합
        ans.pop_back();
    }
}

void pmt(){
    if(ans.size()==k){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(ck[i]==1)    continue;
        ck[i] = 1;
        ans.push_back(arr[i]);
        pmt();
        ans.pop_back();
        ck[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    n = 7;
    k = 3;
    // com(0);
    pmt();
    return 0;
}
