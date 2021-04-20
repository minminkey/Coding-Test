#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int>> core;
int N;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int maxCnt = 0;
int maxLength = 0;

int go(vector<vector<int>> &mp, int idx, int d){
    int r = core[idx][0];
    int c = core[idx][1];
    if(r==0||c==0||r==N-1||c==N-1)  return 0;
    int length = 0;
    int nr = r + dr[d];
    int nc = c + dc[d];
    while(nr>=0&&nc>=0&&nr<N&&nc<N){
        if(mp[nr][nc]!=0)   return -1;
        mp[nr][nc] = 2;
        length++;
        nr += dr[d];
        nc += dc[d];
    }
    return length;
}

int tgo(vector<vector<int>> &mp, vector<pair<int,int>> tcore, int idx, int d){
    int r = tcore[idx].first;
    int c = tcore[idx].second;
    if(r==0||c==0||r==N-1||c==N-1)  return 0;
    int length = 0;
    int nr = r + dr[d];
    int nc = c + dc[d];
    while(nr>=0&&nc>=0&&nr<N&&nc<N){
        if(mp[nr][nc]!=0)   return -1;
        length++;
        nr += dr[d];
        nc += dc[d];
    }
    return length;
}

void dfs(vector<vector<int>> mp, int idx, int cnt, int length){
    if(core.size()-idx+cnt<maxCnt)  return;
    if(idx == core.size()){
        if(cnt > maxCnt){
            maxLength = length;
            maxCnt = cnt;
        }
        else if(cnt==maxCnt && length<maxLength){
            maxLength = length;
        }
        return;
    }
    for(int i=2; i<core[idx].size(); i++){
        vector<vector<int>> tmp = mp;
        int l = go(tmp, idx, core[idx][i]);
        if(l==-1)   continue;
        dfs(tmp, idx+1, cnt+1, length+l);
    }
    dfs(mp, idx+1, cnt, length);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        while(core.size()!=0)   core.pop_back();
        cin>>N;
        maxLength = 0;
        maxCnt = 0;
        vector<vector<int>> mp;
        vector<pair<int, int>> tcore;
        for(int i=0; i<N; i++){
            vector<int> tmp;
		    for(int j=0; j<N; j++){
                int k;
                cin>>k;
                if(k==1)   tcore.push_back({i, j});
                tmp.push_back(k);
            }
            mp.push_back(tmp);
        }
        for(int i=0; i<tcore.size(); i++){
            vector<int> tmp;
            tmp.push_back(tcore[i].first);
            tmp.push_back(tcore[i].second);
            vector<vector<int>> kmp = mp;
            for(int d=0; d<4; d++){
                int l = tgo(kmp, tcore, i, d);
                if(l!=-1){
                    tmp.push_back(d);
                    if(l==0)    break;
                }
            }
            if(tmp.size()!=2){
                core.push_back(tmp);
            }
        }
        dfs(mp, 0, 0, 0);
        cout<<"#"<<test_case<<' '<<maxLength<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}