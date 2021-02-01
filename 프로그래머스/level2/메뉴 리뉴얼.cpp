#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

map<string, int> m[11];

void dfs(string order, int target, string now, int idx){
    if(now.length()==target){
        if(m[target].find(now)==m[target].end())    m[target][now] = 1;
        else                                        m[target][now]++;
        return;
    }
    for(int i=idx; i<order.length(); i++){
        string tmp = now + order[i];
        dfs(order, target, tmp, i+1);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        for(int j=0; j<course.size(); j++){
            dfs(orders[i], course[j], "", 0);
        }
    }
    for(int i=0; i<course.size(); i++){
        map<string, int>::iterator it;
        int Max = 0;
        for(it = m[course[i]].begin(); it!=m[course[i]].end(); it++){
            Max = max(Max, it->second);
        }
        if(Max<2)   continue;
        for(it = m[course[i]].begin(); it!=m[course[i]].end(); it++){
            if(it->second == Max)   answer.push_back(it->first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}