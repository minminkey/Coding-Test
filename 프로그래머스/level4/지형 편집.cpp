#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>> land;
int N;

long long cal(int layer, int P, int Q){
    long long sum = 0;
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(land[r][c]<layer){
                sum += (long long)P*(layer-land[r][c]);
            }
            else if(land[r][c]>layer){
                sum += (long long)Q*(land[r][c]-layer);
            }
        }
    }
    return sum;
}

long long solution(vector<vector<int>> Land, int P, int Q) {
    long long answer = -1;
    land = Land;
    N = land.size();
    vector<int> layers;
    int left = 0x3f3f3f3f;
    int right = 0;
    int mid;
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(left>land[r][c]) left = land[r][c];
            if(right<land[r][c]) right = land[r][c];
    //         layers.push_back(land[r][c]);
        }
    }
    // sort(layers.begin(), layers.end());
    // layers.erase(unique(layers.begin(), layers.end()), layers.end());
    while(left<=right){
        mid = (left+right)/2;
        if(left == right)   break;
        long long calLeft = cal(mid, P, Q);
        long long calRight = cal(mid+1, P, Q);
        if(calLeft<calRight){
            right = mid;
        }
        else if(calLeft>calRight){
            left = mid+1;
        }
        else    break;
    }
    answer = cal(mid, P, Q);
    return answer;
}