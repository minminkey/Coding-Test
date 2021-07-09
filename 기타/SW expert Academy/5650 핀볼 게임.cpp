#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int mp[101][101];
pair<int,int> warmhole[101][101];
int wr[5];
int wc[5];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

pair<int,int> go(int sr, int sc, int r, int c, int d){
	int nr = r;
	int nc = c;
	while(1){
		nr += dr[d];
		nc += dc[d];
		if(nr<0||nc<0||nr>=N||nc>=N||mp[nr][nc]==-1||(mp[nr][nc]>=1&&mp[nr][nc]<=5)){
			return {nr, nc};
		}
		if(nr == sr && nc == sc)	return {nr, nc};
		if(mp[nr][nc]>=6&&mp[nr][nc]<=10){
			int tr = warmhole[nr][nc].first;
			int tc = warmhole[nr][nc].second;
			nr = tr;
			nc = tc;
		}
	}
}

int search(int sr, int sc, int sd){
	pair<int, int> next;
	int r = sr;
	int c = sc;
	int d = sd;
	int cnt = 0;
	while(1){
		next = go(sr, sc, r, c, d);
		r = next.first;
		c = next.second;
		if(mp[r][c] == -1)	return cnt;
		if(r == sr && c == sc)	return cnt;
		cnt++;
		if(r<0||c<0||r>=N||c>=N||mp[r][c] == 5){
			d = (d+2)%4;
		}
		else if(mp[r][c] == 1){
			if(d == 3)		d = 0;
			else if(d == 2)	d = 1;
			else			d = (d+2)%4;
		}
		else if(mp[r][c] == 2){
			if(d==0)		d = 1;
			else if(d==3)	d = 2;
			else			d = (d+2)%4;
		}
		else if(mp[r][c] == 3){
			if(d==0)		d = 3;
			else if(d==1)	d = 2;
			else			d = (d+2)%4;
		}
		else if(mp[r][c] == 4){
			if(d==1)		d = 0;
			else if(d==2)	d = 3;
			else 			d = (d+2)%4;
		}
		// cout<<r<<' '<<c<<' '<<d<<endl;
	}
}

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int ans = 0;
		cin>>N;
		for(int i=0; i<100; i++){
			for(int j=0; j<100; j++){
				mp[i][j] = 0;
				warmhole[i][j] = {-1, -1};
			}
		}
		for(int i=0; i<5; i++){
			wr[i] = -1;
			wc[i] = -1;
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin>>mp[i][j];
				if(mp[i][j]>=6&&mp[i][j]<=10){
					if(wr[mp[i][j]-6]==-1){
						wr[mp[i][j]-6] = i;
						wc[mp[i][j]-6] = j;
					}
					else{
						warmhole[i][j] = {wr[mp[i][j]-6], wc[mp[i][j]-6]};
						warmhole[wr[mp[i][j]-6]][wc[mp[i][j]-6]] = {i, j};
					}
				}
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(mp[i][j] == 0){
					for(int d=0; d<4; d++){
						ans = max(ans, search(i, j, d));
						// if(ans == 10)	cout<<i<<' '<<j<<' '<<d<<endl;
					}
				}
			}
		}
		cout<<"#"<<test_case<<' '<<ans<<endl;
		// cout<<search(0,0,0)<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}