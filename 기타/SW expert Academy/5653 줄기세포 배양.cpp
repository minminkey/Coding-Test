#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int board[700][700];
int live[700][700];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct cmp {
   bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
      int ar = a.first;
      int ac = a.second.first;
      int br = b.first;
      int bc = b.second.first;
      return board[ar][ac]>board[br][bc];
   }
};


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
      
      priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> active;
      priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> non;
      queue<pair<int,pair<int,int>>> ready;
      int N, M, K;
      int now = 1;
      for(int i=0; i<700; i++){
         for(int j=0; j<700; j++){
            board[i][j] = 0;
            live[i][j] = 0;
         }
      }
      cin>>N>>M>>K;
      for(int r=400; r<400+N; r++){
         for(int c=400; c<400+M; c++){
            cin>>board[r][c];
            if(board[r][c] != 0){
               live[r][c] = 1;
               non.push({r, {c, board[r][c]}});
            }
         }
      }
      while(now<=K){
         // cout<<"non "<<non.size()<<" active "<<active.size()<<'\n';
         vector<pair<int,pair<int,int>>> tmp;
         while(!ready.empty()){
            int r = ready.front().first;
            int c = ready.front().second.first;
            int v = ready.front().second.second;
            ready.pop();
            // cout<<"ready "<<r<<' '<<c<<' '<<v<<endl;
            for(int i=0; i<4; i++){
               int nr = r+dr[i];
               int nc = c+dc[i];
               // cout<<nr<<' '<<nc<<' '<<live[nr][nc]<<endl;1
               if(live[nr][nc]==0&&now+v>board[nr][nc]){
                  board[nr][nc] = now+v;
                  tmp.push_back({nr, {nc, v}});
               }
            }
         }
         for(int i=0; i<tmp.size(); i++){
            int r = tmp[i].first;
            int c = tmp[i].second.first;
            int v = tmp[i].second.second;
            if(board[r][c] == now+v){
               non.push({r, {c, v}});
               live[r][c] = 1;
            } 
         }
         while(!non.empty()){
            int r = non.top().first;
            int c = non.top().second.first;
            int v = non.top().second.second;
            if(board[r][c] == now){
               // cout<<r<<' '<<c<<' '<<v<<endl;
               board[r][c] = now+v;
               active.push({r, {c, v}});
               ready.push({r, {c, v}});
               non.pop();
            }
            else     break;
         }
         while(!active.empty()){
            int r = active.top().first;
            int c = active.top().second.first;
            int v = active.top().second.second;
            if(board[r][c] == now){
               live[r][c] = -1;
               active.pop();
            }
            else  break;
         }
         now++;
      }
      // cout<<"non "<<non.size()<<" active "<<active.size()<<'\n';

      int ans = 0;
      for(int i=0; i<700; i++){
         for(int j=0; j<700; j++){
            if(live[i][j] == 1)  ans++;
         }
      }
      cout<<"#"<<test_case<<' '<<ans<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}