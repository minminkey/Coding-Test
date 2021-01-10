#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tile;
    tile.push_back(0);
    tile.push_back(1);
    tile.push_back(2);
    for(int i=3; i<=n; i++){
        tile.push_back((tile[i-1]+tile[i-2])%1000000007);
    }
    answer = tile[n];
    return answer;
}