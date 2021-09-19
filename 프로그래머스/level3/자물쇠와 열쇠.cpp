#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> key;
vector<vector<int>> lock;
int ansCnt = 0;
int M, N;

void rotate(){
    vector<vector<int>> tmp = key;
    int tr = M-1;
    int tc = 0;
    for(int r=0; r<M; r++){
        for(int c=0; c<M; c++){
            key[r][c] = tmp[tr][tc];
            tr--;
        }
        tc++;
        tr = M-1;
    }
}

bool ck(int sr, int sc){
    int cnt = 0;
    for(int r=0; r<M; r++){
        for(int c=0; c<M; c++){
            int nr = r+sr;
            int nc = c+sc;
            if(nr<0||nc<0||nr>=N||nc>=N)    continue;
            if(lock[nr][nc]==0&&key[r][c]==1) cnt++;
            if(lock[nr][nc]==1&&key[r][c]==1)   return false;
        }
    }
    if(ansCnt == cnt)   return true;
    return false;
}

bool solution(vector<vector<int>> Key, vector<vector<int>> Lock) {
    bool answer = true;
    key = Key;
    lock = Lock;
    M = key.size();
    N = lock.size();
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(lock[r][c] == 0) ansCnt++;
        }
    }
    for(int i=0; i<4; i++){
        for(int sr=1-M; sr<N; sr++){
            for(int sc=1-M; sc<N; sc++){
                if(ck(sr, sc))  return true;
            }
        }
        rotate();
    }
    return false;
}