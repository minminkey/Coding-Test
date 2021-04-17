#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct Node{
	
	int x;
	int y;
	int idx;
};



Node customer[10];
bool visit[10];

int N;
int startx,starty,endx,endy;
int result ;
int current ;

void DFS(int x, int y, int count)
{
	

	if(count == N )
	{
		
		current += abs(endx-x) + abs(endy -y);
		
		if(result > current)
		{
			
			result = current;
			
		}
		
		current -= abs(endx-x) + abs(endy -y);
	}
	else
	{
		
	

	
	for(int i = 0; i < N; i++)
	{
		
		if(!visit[i])
		{
			visit[i] = true;
			current += abs(customer[i].x-x)+abs(customer[i].y-y);
			
			DFS(customer[i].x,customer[i].y,count+1);
			current -= abs(customer[i].x-x)+abs(customer[i].y-y);
			visit[i] = false;
		}
	}
	
	}
	
	
}

int main(void)
{
	
	
	
	
	int test_case;
	cin >> test_case;
	
	for(int tc =1 ; tc <= test_case; tc++)
	{
		
		
		cin >> N;
		
		result = 987654321;
		current = 0;
		
		cin >> startx >> starty;
		cin >> endx >> endy;
		
		
		
		
		for(int i = 0; i < N; i++ )
		{
			
			cin >> customer[i].x >> customer[i].y;
			customer[i].idx = i;
			visit[i] = false;

		}	
		
		DFS(startx,starty, 0);
		
		
		cout << "#"<<tc<<" "<<result<<endl;
		
	}
	
	return 0;
}