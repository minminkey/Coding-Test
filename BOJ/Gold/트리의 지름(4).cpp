#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

vector<pair<int, int>> tree[200001];

int findLong(int start, int type)
{
    queue<pair<int, int>> q;
    int ans = 0;
    int ansNode = -1;
    int visit[200001] = {
        0,
    };
    q.push({start, 0});
    visit[start] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        for (int i = 0; i < tree[node].size(); i++)
        {
            int next = tree[node][i].first;
            if (visit[next] == 1)
                continue;
            visit[next] = 1;
            int ndist = tree[node][i].second + dist;
            if (ans < ndist)
            {
                ansNode = next;
                ans = ndist;
            }
            q.push({next, ndist});
        }
    }
    if (type == 0)
        return ans;
    else
        return ansNode;
}

int main()
{
    int V;
    cin >> V;
    for (int i = 1; i <= V - 1; i++)
    {
        int p, c, d;
        cin >> p >> c >> d;
        tree[p].push_back({c, d});
        tree[c].push_back({p, d});
    }
    if (V == 1)
        cout << 0 << '\n';
    else
        cout << findLong(findLong(1, 1), 0) << '\n';
    return 0;
}