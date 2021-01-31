#include <string>
#include <vector>
#include <iostream>

using namespace std;

string first(string id){
    for(int i=0; i<id.length(); i++){
        if(id[i]>='A'&&id[i]<='Z'){
            id[i] += 32;
        }
    }
    string tmp = "";
    for(int i=0; i<id.length(); i++){
        if(id[i]=='.'||id[i]=='-'||id[i]=='_'||(id[i]>='0'&&id[i]<='9')||(id[i]>='a'&&id[i]<='z'))  tmp += id[i];
    }
    string tmp1 = "";
    tmp1 += tmp[0];
    for(int i=1; i<tmp.length(); i++){
        if(tmp[i-1]=='.'&&tmp[i]=='.')  continue;
        tmp1 += tmp[i];
    }
    if(tmp1[0]=='.'){
        tmp1 = tmp1.substr(1);
    }
    if(tmp1[tmp1.length()-1]=='.')  tmp1.pop_back();
    if(tmp1.compare("")==0){
        tmp1 = "a";
    }
    if(tmp1.length()>=16){
        tmp1 = tmp1.substr(0,15);
    }
    if(tmp1[tmp1.length()-1]=='.')  tmp1.pop_back();
    if(tmp1.length()<=2){
        while(tmp1.length()<3){
            tmp1.push_back(tmp1[tmp1.length()-1]);
        }
    }
    return tmp1;
}
string solution(string new_id) {
    string answer = "";
    answer = first(new_id);
    
    return answer;
}