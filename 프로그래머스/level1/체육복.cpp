#include <stack>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<tuple<int, int>> v;
    stack<tuple<int, int>> st;
    queue<tuple<int, int, int, int, int>> q;
    q.push({1,2,3,4,5});
    while(!q.empty()){
        auto [one, two, three, four, five] = q.front();
        cout<<one<<' '<<two<<' '<<three<<' '<<four<<' '<<five<<endl;
        q.pop();
    }
    return answer;
}