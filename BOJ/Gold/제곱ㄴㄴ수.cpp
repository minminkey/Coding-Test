#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    long long s, b;
    cin >> s >> b;
    long long visit[1000001] = {
        0,
    };
    long long ans = 0;
    for (long long i = 2; i * i <= b; i++)
    {
        long long now = s / (i * i);
        if (now * i * i != s)
            now++;
        for (long long j = now; j * i * i <= b; j++)
        {
            visit[i * i * j - s] = 1;
        }
    }
    for (int i = 0; i < b - s + 1; i++)
    {
        if (visit[i] == 0)
            ans++;
    }
    cout << ans << endl;
}