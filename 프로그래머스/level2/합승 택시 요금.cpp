#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int edge[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0x3f3f3f3f;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==j)    continue;
            edge[i][j] = 0x3f3f3f3f;
        }
    }
    for(int i=0; i<fares.size(); i++){
        int st = fares[i][0];
        int ed = fares[i][1];
        int di = fares[i][2];
        edge[st][ed] = di;
        edge[ed][st] = di;
    }
    for(int k=1; k<=n; k++){
        for(int st=1; st<=n; st++){
            for(int ed=1; ed<=n; ed++){
                edge[st][ed] = min(edge[st][ed], (edge[st][k]+edge[k][ed]));
            }
        }
    }
    for(int mid = 1; mid<=n; mid++){
        if(edge[s][mid] == 0x3f3f3f3f || edge[mid][a] == 0x3f3f3f3f || edge[mid][b] == 0x3f3f3f3f)    continue;
        int dist = edge[s][mid] + edge[mid][a] + edge[mid][b];
        answer = min(answer, dist);
    }
    return answer;
}