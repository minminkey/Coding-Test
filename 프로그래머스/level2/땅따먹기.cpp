#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int s = land.size()-1;
    for(int i=0; i<s; i++){
        land[i+1][0] += max(land[i][1], max(land[i][3], land[i][2]));
        land[i+1][1] += max(land[i][0], max(land[i][3], land[i][2]));
        land[i+1][2] += max(land[i][0], max(land[i][1], land[i][3]));
        land[i+1][3] += max(land[i][0], max(land[i][1], land[i][2]));
    }
    answer = max(land[s][0], max(land[s][1], max(land[s][2], land[s][3])));
    return answer;
}