#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int T;
   cin >> T;
   while (T--)
   {
      int dp[2][100001] = {
          0,
      };
      vector<int> num[2];
      int n;
      cin >> n;
      for (int k = 0; k < 2; k++)
      {
         for (int i = 0; i < n; i++)
         {
            int tmp;
            cin >> tmp;
            num[k].push_back(tmp);
         }
      }
      dp[0][0] = num[0][0];
      dp[1][0] = num[1][0];
      dp[0][1] = dp[1][0] + num[0][1];
      dp[1][1] = dp[0][0] + num[1][1];
      for (int i = 2; i < n; i++)
      {
         dp[0][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]) + num[0][i];
         dp[1][i] = max(max(dp[1][i - 2], dp[0][i - 2]), dp[0][i - 1]) + num[1][i];
      }
      cout << (max(dp[0][n - 1], dp[1][n - 1])) << endl;
   }
   return 0;
}