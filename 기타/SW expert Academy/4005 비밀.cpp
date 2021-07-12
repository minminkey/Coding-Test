#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int info[11][11];
vector<int> child[11];
int length;

void dfs(int s, int cnt, vector<int> visit, vector<int> listen){
	length = max(length, cnt);
	listen[s] = 1;
	for(int i=0; i<child[s].size(); i++){
		int next = child[s][i];
		if(visit[s] == 0&& listen[next] == 0){
			visit[s] = 1;
			listen[next] = 1;
			dfs(next, cnt+1, visit, listen);
			listen[next] = 0;
			visit[s] = 0;
		}
	}
}

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		length = 0;
		for(int i=0; i<11; i++){
			vector<int> tmp;
			child[i] = tmp;
			for(int j=0; j<11; j++){
				info[i][j] = 0;
			}
		}
		int ans[11] = {0, };
		cin>>N>>K;
		for(int i=0; i<K; i++){
			int num;
			int prev;
			cin>>num>>prev;
			// cout<<num<<' '<<prev<<endl;
			for(int j=1; j<num; j++){
				// cout<<"hi"<<j<<' '<<num<<endl;
				int next;
				cin>>next;
				info[prev][next]++;
				prev = next;
			}
		}
		for(int i=1; i<=N; i++){
			int cnt = 0;
			for(int j=1; j<=N; j++){
				if(info[i][j]!=0){
					cnt++;
					child[i].push_back(j);
				}
			}
			ans[i] = cnt;
		}
		for(int i=1; i<=N; i++){
			vector<int> visit;
			vector<int> listen;
			for(int j=0; j<=N; j++){
				visit.push_back(0);
				listen.push_back(0);
			}
			dfs(i, 1, visit, listen);
		}
		cout<<"#"<<test_case<<' ';
		for(int i=1; i<=N; i++){
			cout<<ans[i]<<' ';
		}
		cout<<length<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}