#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

long long factorial(int n) {
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
	vector<int> answer;
	vector <int> v;
	long long slice, now;
	
	for (int i = 1; i <= n; i++)
		v.push_back(i);

	while (1) {
		if (n == 0) {
			break;
		}

		slice = factorial(n) / n;
		now = int((k - 1) / slice);
		answer.push_back(v[now]);
		v.erase(v.begin()+now);
		n--;
		k %= slice;
		if (k == 0)
			k = slice;
	}
	
	return answer;
}