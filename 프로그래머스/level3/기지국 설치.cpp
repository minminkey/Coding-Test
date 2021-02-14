#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    double now = 1;
    double tmp = 2*w + 1;
    for(int i=0; i<stations.size(); i++){
        double start = stations[i]-w;
        double end = stations[i]+w;
        if(start<0) start = 0;
        if(end>n)   end = n;
        double rest = start - now;
        if(rest>0){
            answer += ceil(rest/tmp);
        }
        now = end+1;
    }
    if(now<=n){
        answer += ceil((n+1-now)/tmp);
    }
    return answer;
}