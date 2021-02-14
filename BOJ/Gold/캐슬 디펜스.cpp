#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int N, M, D, Max;
vector<vector<int>> board;
vector<vector<int>> location;

bool ck(vector<vector<int>> tmp){
    for(int i = N-1; i>=0; i--){
        for(int j=0; j<M; j++){
            if(tmp[i][j]==1)    return true;
        }
    }
    return false;
}
void down(vector<vector<int>> &tmp){
    for(int i=N-1; i>=1; i--){
        for(int j=0; j<M; j++){
            tmp[i][j] = tmp[i-1][j];
        }
    }
    for(int i=0; i<M; i++){
        tmp[0][i] = 0;
    }
}
void kill(vector<int> archer){
    vector<vector<int>> before = board;
    vector<vector<int>> after = before;
    int cnt = 0;
    for(int k=0; k<N; k++){
        if(!ck(before))      break;
        after = before;
        for(int i=0; i<archer.size(); i++){
            int row = N;
            int col = archer[i];
            int Min = 100;
            int kr=-1,  kc=-1;
            int flag = 0;
            for(int j=0; j<M; j++){
                int gap= N-D;
                if(gap<0)   gap = 0;
                for(int i=0; i<N; i++){
                    if(before[i][j]==1){
                        int d = abs(row-i)+abs(col-j);
                        if(d>D) continue;
                        if(d<Min){
                            kr = i;
                            kc = j;
                            Min = d;
                        }
                    }
                }
            }
            if((kr!=-1&&kc!=-1)&&after[kr][kc]==1){
                after[kr][kc] = 0;
                cnt++;
            }
        }
        before = after;
        down(before);
    }
    if(Max<cnt) Max = cnt;
}
void locate(vector<int> tmp){
    if(tmp.size()==3){
        location.push_back(tmp);
        return;
    }
    for(int i=tmp.back()+1; i<M; i++){
        tmp.push_back(i);
        locate(tmp);
        tmp.pop_back();
    }
}
int main(){
    cin>>N>>M>>D;
    vector<int> tmp;
    for(int i=0; i<N; i++){
        vector<int> t;
        for(int j=0; j<M; j++){
            int k;
            cin>>k;
            t.push_back(k);
        }
        board.push_back(t);
    }
    for(int i=0; i<=M-3; i++){
        tmp.push_back(i);
        locate(tmp);
        tmp.pop_back();
    }
    for(int i=0; i<location.size(); i++){
        kill(location[i]);
    }
    cout<<Max<<endl;   
}