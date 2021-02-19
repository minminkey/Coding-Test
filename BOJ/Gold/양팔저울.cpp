#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N, Q;
    vector<string> answer;
    int cho[51] = {
        0,
    };
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        cho[i] = t;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int target;
        int visit[33333] = {
            0,
        };
        string ans = "N";
        cin >> target;
        queue<pair<int, int>> q;
        q.push({0, -1});
        visit[15000] = 1;
        while (!q.empty())
        {
            int now = q.front().first;
            int idx = q.front().second + 1;
            q.pop();
            // cout<<"now "<<now<<endl;
            if (idx >= N)
                continue;
            q.push({now, idx});
            if (visit[now + cho[idx] + 15000] == 0)
            {
                visit[now + cho[idx] + 15000] = 1;
                if (target == now + cho[idx])
                {
                    ans = "Y";
                    break;
                }
                else
                {
                    q.push({now + cho[idx], idx});
                }
            }
            if (visit[now - cho[idx] + 15000] == 0)
            {
                visit[now - cho[idx] + 15000] = 1;
                if (target == now - cho[idx])
                {
                    ans = "Y";
                    break;
                }
                else
                {
                    q.push({now - cho[idx], idx});
                }
            }
        }
        answer.push_back(ans);
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}