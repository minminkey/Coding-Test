#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

vector<pair<int, int>> tree[100001];

int findLong(int start, int type)
{
    queue<pair<int, int>> q;
    int ans = 0;
    int ansNode = -1;
    int visit[100001] = {
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
    for (int i = 1; i <= V; i++)
    {
        int num;
        int node, edge;
        cin >> num;
        cin >> node;
        while (node != -1)
        {
            cin >> edge;
            tree[num].push_back({node, edge});
            cin >> node;
        }
    }
    cout << findLong(findLong(1, 1), 0) << '\n';
}