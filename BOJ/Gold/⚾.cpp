#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int play(vector<int> player, vector<vector<int>> points){
    int ans = 0;
    int now = 0;
    for(int i=0; i<points.size(); i++){
        int out = 0;
        int field[4] = {0, };
        while(out<3){
            int hit = points[i][player[now]];
            if(hit==0){
                out++;
            }
            else{
                field[0] = 1;
                for(int i=3; i>=0; i--){
                    if(field[i]==1){
                        if(i+hit>=4)    ans++;
                        else            field[i+hit] = 1;
                        field[i] = 0;
                    }
                }
            }
            now = (now+1)%9;
        }
    }
    return ans;
}

int main(){
    int N;
    vector<vector<int>> points;
    vector<int> before;
    for(int i=2; i<=9; i++){
        before.push_back(i);
    }
    cin>>N;
    for(int i=0; i<N; i++){
        vector<int> tmp;
        tmp.push_back(0);
        for(int j=0; j<9; j++){
            int t;
            cin>>t;
            tmp.push_back(t);
        }
        points.push_back(tmp);
    }
    int k = 1;
    int maxPoint = 0;
    do{
        vector<int> player = before;
        player.insert(player.begin()+3, 1);
        maxPoint = max(maxPoint, play(player, points));
    }while(next_permutation(before.begin(), before.end()));
    cout<<maxPoint<<'\n';
}