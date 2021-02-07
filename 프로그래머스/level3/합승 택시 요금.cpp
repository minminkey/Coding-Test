#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int Map[201][201];
int INF = 0x3f3f3f3f;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)    continue;
            Map[i][j] = INF;
        }
    }
    for(int i=0; i<fares.size(); i++){
        Map[fares[i][0]][fares[i][1]] = fares[i][2];
        Map[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j||j==k||i==k)    continue;
                if(Map[i][k]!=INF&&Map[k][j]!=INF)    Map[i][j] = min(Map[i][j], Map[i][k]+Map[k][j]);
            }
        }
    }
    answer = Map[s][a] + Map[s][b];
    for(int i=1; i<=n; i++){
        if(Map[s][i]!=INF&&Map[i][a]!=INF&&Map[i][b]!=INF){
            answer = min(answer, Map[s][i]+Map[i][a]+Map[i][b]);
        }
    }
    return answer;
}