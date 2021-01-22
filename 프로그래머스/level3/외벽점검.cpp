#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    sort(dist.begin(), dist.end());
    for (int i = 0; i < weak.size(); i++) {
        int tmp = weak[0] + n;
        for (int j = 1; j < weak.size(); j++) {
            weak[j - 1] = weak[j];
        }
        weak[weak.size() - 1] = tmp;
        do {
            int w = 0;
            int d = 0;
            for (d = 0; d < dist.size(); d++) {
                int fin = weak[w] + dist[d];
                while (fin >= weak[w]) {
                    w++;
                    if (w == weak.size()) {
                        break;
                    }
                }
                if (w == weak.size()) {
                    break;
                }
            }
            if (w == weak.size()) {
                if (answer == -1 || d + 1 < answer) {
                    answer = d + 1;
                }
            }
        } while (next_permutation(dist.begin(), dist.end()));
    }
    return answer;
}