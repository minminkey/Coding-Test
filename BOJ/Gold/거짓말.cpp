#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    int num;
    int ans = 0;
    int know[51] = {
        0,
    };
    cin >> N >> M >> num;
    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        know[tmp] = 1;
    }
    vector<vector<int>> people;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        int flag = 0;
        cin >> tmp;
        vector<int> per;
        for (int j = 0; j < tmp; j++)
        {
            int t;
            cin >> t;
            per.push_back(t);
            if (know[t] == 1)
            {
                flag = 1;
                // break;
            }
        }
        people.push_back(per);
    }
    for (int k = 0; k < M; k++)
    {
        for (int i = 0; i < people.size(); i++)
        {
            int flag = 0;
            for (int j = 0; j < people[i].size(); j++)
            {
                if (know[people[i][j]] == 1)
                {
                    // ans++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                for (int j = 0; j < people[i].size(); j++)
                {
                    know[people[i][j]] = 1;
                }
            }
        }
    }
    for (int i = 0; i < people.size(); i++)
    {
        int flag = 0;
        for (int j = 0; j < people[i].size(); j++)
        {
            if (know[people[i][j]] == 1)
            {
                ans++;
                flag = 1;
                break;
            }
        }
    }
    cout << M - ans << '\n';
}