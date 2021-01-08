#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int N = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()),nums.end());
    int answer = 0;
    int tmp = nums.size();
    answer = min(N/2, tmp);
    return answer;
}