#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        int pre[501] = {
            0,
        };
        vector<int> in[501];
        cin >> n;
        int cnt = 0;
        vector<int> t;
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            cin >> tmp;
            in[tmp] = t;
            t.push_back(tmp);
            pre[tmp] = cnt++;
        }
        cin >> m;
        int foo = 0;
        for (int i = 0; i < m; i++)
        {
            int u, d;
            cin >> u >> d;
            if (find(in[d].begin(), in[d].end(), u) != in[d].end())
            {
                pre[d]--;
                pre[u]++;
            }
            else
            {
                pre[u]--;
                pre[d]++;
            }
        }
        vector<int> ans;
        cnt = 0;
        int flag1 = 0;
        for (int i = 1; i <= n; i++)
        {
            int flag = 0;
            for (int j = 1; j <= n; j++)
            {
                if (pre[j] == cnt)
                {
                    if (flag == 1)
                    {
                        flag = 2;
                        break;
                    }
                    ans.push_back(j);
                    flag = 1;
                }
            }
            cnt++;
            if (flag == 0)
            {
                flag1 = 1;
                break;
            }
            else if (flag == 2)
            {
                flag1 = 2;
                break;
            }
        }
        if (flag1 == 1)
        {
            cout << "IMPOSSIBLE";
        }
        else if (flag1 == 2)
        {
            cout << "?";
        }
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
