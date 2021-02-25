#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int n;
vector<int> edge[3001];
int ck[3001];

void dfs(int node, int pre, vector<int> before, int visit[])
{
    for (int i = 0; i < edge[node].size(); i++)
    {
        int next = edge[node][i];
        if (ck[next] == 1 || pre == next)
            continue;
        if (visit[next] == 1)
        {
            for (int i = before.size() - 1; i >= 0; i--)
            {
                if (before[i] == next)
                {
                    ck[before[i]] = 1;
                    break;
                }
                ck[before[i]] = 1;
            }
            continue;
        }
        visit[next] = 1;
        vector<int> tmp = before;
        tmp.push_back(next);
        dfs(next, node, tmp, visit);
        visit[next] = 0;
    }
}
struct Node
{
    int node;
    int dist;
    vector<int> pre;
};
int main()
{
    cin >> n;
    int ans[3001] = {
        0,
    };
    for (int i = 1; i <= n; i++)
    {
        ans[i] = -1;
        int s, e;
        cin >> s >> e;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }
    vector<int> ep;
    int visit[3001] = {
        0,
    };
    dfs(1, -1, ep, visit);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != -1)
            continue;
        if (ck[i] == 1)
        {
            ans[i] = 0;
            continue;
        }
        queue<struct Node> q;
        vector<int> tmp;
        tmp.push_back(i);
        int vt[3001] = {
            0,
        };
        struct Node start
        {
            i, 0, tmp
        };
        q.push(start);
        vt[i] = 1;
        while (!q.empty())
        {
            int now = q.front().node;
            int dist = q.front().dist;
            vector<int> pre = q.front().pre;
            q.pop();
            int flag = 0;
            for (int j = 0; j < edge[now].size(); j++)
            {
                int next = edge[now][j];
                if (vt[next] == 1)
                    continue;
                if (ck[next] == 1 || ans[next] == 0)
                {
                    int f = 1;
                    for (int k = pre.size() - 1; k >= 0; k--)
                    {
                        ans[pre[k]] = f++;
                    }
                    flag = 1;
                    break;
                }
                if (flag == 1)
                    break;
                vt[next] = 1;
                pre.push_back(next);
                struct Node in
                {
                    next, dist + 1, pre
                };
                q.push(in);
                pre.pop_back();
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
}