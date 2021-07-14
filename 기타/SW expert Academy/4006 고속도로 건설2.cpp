#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int parent[50001];
vector<pair<int, pair<int, int>>> pq;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
	if(x<y)	parent[y] = x;
	else    parent[x] = y;
    return 1;
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
	return a.first>b.first;
}

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		int ans = 0;
		pq.clear();
		cin>>N>>M;
		for(int i=0; i<M; ++i){
			int s, e, c;
			cin>>s>>e>>c;
			pq.push_back({-1*c,{s,e}});
		}
		for(int i=1; i<=N; ++i){
			parent[i] = i;
		}
		int cnt = 1;
		sort(pq.begin(), pq.end(), cmp);
		for(int i=0; i<M; ++i){
			int c = pq[i].first*-1;
			int s = pq[i].second.first;
			int e = pq[i].second.second;
			if(merge(s, e)){
				ans += c;
				cnt++;
			}
			if(cnt>N)	break;
		}
		cout<<'#'<<test_case<<' '<<ans<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}