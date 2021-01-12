#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<vector<int>> board;
int answer = 100;
int cnt = 0;

int ck(vector<vector<int>> tmp, int r, int c){
    int k;
    for(k=5; k>=1; k--){
        if(r+k>10||c+k>10)  continue;
        int flag = 1;
        for(int i=r; i<r+k; i++){
            for(int j=c; j<c+k; j++){
                if(tmp[i][j]==0){
                    flag = 0;
                    break;
                }
            }
            if(flag==0) break;
        }
        if(flag==1){
            return k;
        }
    }
}
vector<vector<int>> put(vector<vector<int>> tmp, int r, int c, int size){
    for(int i=r; i<r+size; i++){
        for(int j=c; j<c+size; j++){
            tmp[i][j] = 0;
        }
    }
    return tmp;
}
void fill(vector<vector<int>> before, int rest[6], int r, int c){
    if(c>=10){
        fill(before, rest, r+1, 0);
        return;
    }
    if(r==10){
        answer = min(cnt, answer);
        return;
    }
    if(before[r][c]==0){
        fill(before, rest, r, c+1);
        return;
    }
    int size = ck(before, r, c);
    for (int k = size; k >= 1; k--)
    {
        if (rest[k] - 1 < 0)
            continue;
        if (r + k > 10 || c + k > 10)
            continue;
        rest[k]--;
        cnt++;
        fill(put(before, r, c, k), rest, r, c+k);
        rest[k]++;
        cnt--;
    }
}
int main(){
    int rest[6] = {5, 5, 5, 5, 5, 5};
    for(int i=0; i<10; i++){
        vector<int> tmp;
        for(int j=0; j<10; j++){
            int t;
            cin>>t;
            tmp.push_back(t);
        }
        board.push_back(tmp);
    }
    fill(board, rest, 0, 0);
    if(answer == 100)   answer = -1;
    cout<<answer<<endl;
}