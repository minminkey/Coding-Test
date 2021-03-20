#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

double point[5];

struct Movie{
    int r,c;
    double p;
    int view;
    char type;
};
// vector<struct Movie> notView;
vector<struct Movie> View;

bool cmp(struct Movie a, struct Movie b){
    if(a.view == b.view){
        if(a.p==b.p){
            if(a.r==b.r){
                return a.r<b.r;
            }
            return a.r<b.r;
        }
        return a.p>b.p;
    }
    return a.view<b.view;
}

int mp[101][11];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   for(int i=0; i<5; i++){
       cin>>point[i];
   }
   int n,m;
   cin>>n>>m;
   for(int i=0; i<n; i++){
       string s;
       cin>>s;
       for(int j=0; j<s.length(); j++){
           if(s[j]=='O'){
               mp[i][j] = 2;
           }
           else if(s[j]=='Y'){
               mp[i][j] = 1;
           }
           else{
               mp[i][j] = 0;
           }
       }
   }
   for(int i=0; i<n; i++){
       string s;
       cin>>s;
       for(int j=0; j<s.length(); j++){
           if(mp[i][j]==0)  continue;
           struct Movie tmp = {i, j, 0.0, mp[i][j], s[j]};
           tmp.p = point[s[j]-'A'];
            View.push_back(tmp);
       }
   }
   sort(View.begin(), View.end(), cmp);
   for(int i=0; i<View.size(); i++){
       printf("%c %.1f %d %d\n",View[i].type, View[i].p, View[i].r, View[i].c);
   }
   return 0;
}