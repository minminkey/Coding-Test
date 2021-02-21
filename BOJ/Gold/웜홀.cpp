#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int INF = 0x3f3f3f3f;

int main()
{
    int tc;
    cin >> tc;
    vector<string> ans;
    while (tc--)
    {
        int N, M, W;
        cin >> N >> M >> W;
        vector<vector<pair<int, int>>> edge(N + 1);
        vector<int> dist(N + 1, INF);
        dist[1] = 0;
        for (int i = 0; i < M; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edge[s].push_back({e, t});
            edge[e].push_back({s, t});
        }
        for (int i = 0; i < W; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edge[s].push_back({e, -t});
        }
        int flag = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int k = 0; k < edge[j].size(); k++)
                {
                    int s = j;
                    int e = edge[s][k].first;
                    int t = edge[s][k].second;
                    if (dist[s] + t < dist[e])
                    {
                        dist[e] = dist[s] + t;
                        if (i == N)
                            flag = 1;
                    }
                }
            }
        }
        if (flag == 0)
        {
            ans.push_back("NO");
        }
        else
        {
            ans.push_back("YES");
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
}
