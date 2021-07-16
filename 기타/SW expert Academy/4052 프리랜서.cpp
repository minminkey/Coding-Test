#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<pair<int, pair<int, int>>> job;
int dp[501];
int day[10001];


bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
	return a.second.second < b.second.second;
}

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		job.clear();
		memset(dp, 0, sizeof(dp));
		int ans;
		cin>>N>>M;
		for(int i=0; i<N; i++){
			int s, e, c;
			cin>>s>>e>>c;
			job.push_back({c,{s,e}});
		}
		sort(job.begin(), job.end(), cmp);
		dp[0] = job[0].first;
		// cout<<job[0].second.second;
		// cout<<0<<' '<<dp[0]<<endl;
		for(int i=1; i<N; i++){
			int idx = -1;
			for(int j=0; j<i; j++){
				if(job[j].second.second>=job[i].second.first)	break;
				idx = j;
			}
			if(idx>=0) 	dp[i] = max(dp[i-1], job[i].first + dp[idx]);
			else		dp[i] = max(dp[i-1], job[i].first);
			// cout<<i<<' '<<dp[i]<<endl;
		}
		ans = dp[N-1];

		cout<<'#'<<test_case<<' '<<ans<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}