#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
 
char Map[110][110];
int row, col;
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
int safe(int x, int y)
{
    if(0 <= x && x < row && 0 <= y && y < col)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
bool solve(int x, int y)
{        
    char Find = Map[x][y];
    
    for(int i = 0; i < 4; i++)
    {
        int xpos = x + dx[i];
        int ypos = y + dy[i];
        
        while(safe(xpos, ypos) == 1 && (Map[xpos][ypos] == '.' || Map[xpos][ypos] == Find))
        {
            if(Map[xpos][ypos] == Find)
            {
                Map[x][y] = '.';
                Map[xpos][ypos] = '.';
                return true;
            }
            
            for(int j = 0; j < 4; j++)
            {
                if(i == j || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 2 && j == 3) || (i == 3 && j == 2))
                {
                    continue;
                }
 
                int nx = xpos + dx[j];
                int ny = ypos + dy[j];
               
                while(safe(nx, ny) == 1 && (Map[nx][ny] == '.' || Map[nx][ny] == Find))
                {
                    if(Map[nx][ny] == Find)
                    {
                        Map[x][y] = '.';
                        Map[nx][ny] = '.';
                        return true;
                    }
                    
                    nx += dx[j];
                    ny += dy[j];
                }
            }
 
            xpos += dx[i];
            ypos += dy[i];
        }   
    }
    
    return false;
}
 
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) 
{
    string answer = "";
    row = m;
    col = n;
    
    vector<pair<char, pair<int, int>>> reserve;   
    map<char, int> alphabet_check;  
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Map[i][j] = board[i][j];
            
            if('A' <= Map[i][j] && Map[i][j] <= 'Z' && alphabet_check[Map[i][j]] == 0)
            {
                alphabet_check[Map[i][j]] = 1;
                reserve.push_back({Map[i][j], {i, j}});
            }
        }
    }
    sort(reserve.begin(), reserve.end());
    
    bool Flag = true;
    while(Flag)
    {
        Flag = false;
        
        for(int i = 0; i < reserve.size(); i++)
        {
            Flag = solve(reserve[i].second.first, reserve[i].second.second);
            
            if(Flag == true)
            {
                answer += reserve[i].first;
                reserve.erase(reserve.begin()+i);
                
                break;
            }
        }
    }
 
    if(reserve.size() != 0)
    {
        answer = "IMPOSSIBLE";
    }
    
    return answer;
}
