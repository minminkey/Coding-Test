#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    for(int i=0; i<skill_trees.size(); i++){
        int index = 0;
        for(int j=0; j<skill_trees[i].size(); j++){
            int flag = -1;
            for(int k=0; k<skill.size(); k++){
                if(skill[k]==skill_trees[i][j]){
                    flag = k;
                    break;
                }
            }
            if(flag != -1){
                if(flag != index){
                    answer--;
                    break;
                }
                else {
                    index++;
                }
            }
        }
    }
    return answer;
}
