#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int minSum = 0x3f3f3f3f;

void rotate(vector<vector<int>> &a, int r, int c, int s){
    if(s==0)    return;
    int tmp = a[r-s][c-s];
    for(int row=r-s; row<r+s; row++){
        a[row][c-s] = a[row+1][c-s];
    }
    for(int col=c-s; col<c+s; col++){
        a[r+s][col] = a[r+s][col+1];
    }
    for(int row=r+s; row>r-s; row--){
        a[row][c+s] = a[row-1][c+s];
    }
    for(int col=c+s; col>c-s; col--){
        a[r-s][col] = a[r-s][col-1];
    }
    a[r-s][c-s+1] = tmp;
    rotate(a, r,c,s-1);
}
void per(vector<vector<int>> a, vector<vector<int>> info, int visit[], int cnt){
    if(cnt==info.size()){
        for(int i=1; i<=n; i++){
            int sum = 0;
            for(int j=1; j<=m; j++){
                sum += a[i][j];
            }
            minSum = min(minSum, sum);
        }
        return;
    }
    for(int i=0; i<info.size(); i++){
        if(visit[i]==1) continue;
        vector<vector<int>> tmp = a;
        rotate(tmp, info[i][0], info[i][1], info[i][2]);
        visit[i] = 1;
        per(tmp, info, visit, cnt+1);
        visit[i] = 0;
    }
}
int main(){
    vector<vector<int>> info;
    vector<vector<int>> a(51, vector<int>(51));
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int r,c,s;
        cin>>r>>c>>s;
        vector<int> tmp;
        tmp.push_back(r);
        tmp.push_back(c);
        tmp.push_back(s);
        info.push_back(tmp);
    }
    int visit[10] = {0,};
    per(a, info, visit, 0);
    cout<<minSum<<'\n';
}