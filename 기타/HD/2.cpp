#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> solution(vector<string> a) {
    vector<bool> answer;
    for(int i=0; i<a.size(); i++){
        string str = a[i];
        int cnt = 0;
        for(int j=0; j<str.length(); j++){
            if(str[j] == 'a')   cnt++;
        }
        int l = 0;
        int r = str.length()-1;
        int f = 10;
        while(l!=r){
            if(str[l] == 'b' && str[r] == 'b'){
                int flag = 0;
                if(cnt == 0)    break;
                for(int k=0; k<cnt; k++){
                    if(str[l] == 'b'&&str[r]=='b'){
                        l++;
                        r--;
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    break;
                }
            }
            else if(str[l] == 'a' && str[r] != 'a'){
                l++;
                cnt--;
            }
            else if(str[l] != 'a' && str[r] == 'a'){
                r--;
                cnt--;
            }
            else if(str[l]=='a' && str[r] == 'a'){
                l++;
                cnt--;
            }
        }
        if(l==r && str[l] == 'a')    answer.push_back(true);
        else        answer.push_back(false);
    }
    return answer;
}