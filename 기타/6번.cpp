#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pro[11];
int ans = 0;

void findAns(int idx, int s, int value)
{
    if (idx < 0)
    {
        ans = max(value, ans);
        return;
    }
    findAns(idx - 1, (s + 1) * 2, value + pro[idx][s]);
    findAns(idx - 1, s * 2, value + pro[idx][s + 1]);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pro[0].push_back(tmp);
    }
    int num = 0;
    int t = n;
    while (t != 1)
    {
        t = t / 2;
        num++;
    }
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < pro[i].size(); j += 2)
        {
            int input = max(pro[i][j], pro[i][j + 1]);
            pro[i + 1].push_back(input);
        }
    }
    findAns(num - 1, 0, 0);
    cout << ans << endl;
    return 0;
}