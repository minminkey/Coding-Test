#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int g;
    int s;
    int use;
    int remain;
    int idx;
} City;

vector<City> seq;
vector<int> g;
vector<int> s;
vector<int> w;
vector<int> t;

bool cmp(City &a, City &b){
    return a.g < b.g;
}

bool ck(int a, int b, int time){
    vector<int> vol;
    int gsum = 0;
    int ssum = 0;
    for(int i=0; i<t.size(); i++){
        int cnt = time/t[i]-1;
        cnt = cnt/2;
        cnt++;
        vol.push_back(cnt*w[i]);
    }
    for(int i=0; i<seq.size(); i++){
        int nowG = min(vol[seq[i].idx], seq[i].g);
        vol[seq[i].idx] -= nowG;
        int nowS = min(vol[seq[i].idx], seq[i].s);
        vol[seq[i].idx] -= nowS;
        gsum += nowG;
        ssum += nowS;
        seq[i].use = nowG;
        seq[i].remain = seq[i].s - nowS;
    }
    if(gsum<a)  return false;
    if(ssum>=b) return true;
    for(int i=0; i<seq.size(); i++){
        int nowS = min(seq[i].use, seq[i].remain);
        ssum += nowS;
        gsum -= nowS;
        if(ssum>=b&&gsum>=a)    return true;
        if(ssum<b&&gsum<a)      return false;
    }
}

long long solution(int a, int b, vector<int> G, vector<int> S, vector<int> W, vector<int> T) {
    long long answer = -1;
    G = g;
    S = s;
    W = w;
    T = t;
    for(int i=0; i<g.size(); i++){
        City city;
        city.g = g[i];
        city.s = s[i];
        city.idx = i;
        seq.push_back(city);
    }
    sort(seq.begin(), seq.end(), cmp);
    long long l = 0;
    long long r = 1000000000;
    long long mid;
    while(l<=r){
        mid = (l+r)/2;
        if(ck(a,b,mid)){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    answer = mid;
    return answer;
}