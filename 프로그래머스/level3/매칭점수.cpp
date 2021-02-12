#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <string, int> m;
struct Wed{
    double basic;
    double linkNum;
    vector<int> link;
    double linkPoint;
    double matching;
};
struct Wed wed[21] = {0,};

void findWord(int idx, string page, string word){
    int start = page.find("<body>")+6;
    int end = page.find("</body>");
    int flag = 0;
    int flag2 = 0;
    string s = "";
    for(int i = start; i<end; i++){
        string tmp = page.substr(i,8);
        if(tmp.compare("<a href=")==0){
            wed[idx].linkNum++;
            int e = page.find('"',i+9);
            string url = page.substr(i+9, e-i-9);
            if(m.find(url)!=m.end())    wed[idx].link.push_back(m.find(url)->second);
            i = e;
            continue;
        }
        if(page[i]=='<')    flag = 1;
        if(page[i]=='>'){
            flag = 0;
            continue;
        }
        if(page[i]=='\n')   continue;
        if(flag == 1)       continue;
        s = page.substr(i-1,word.length()+2);
        if(s[0]>='a'&&s[0]<='z')    continue;
        if(s.length()==word.length()+2){
            if(s[s.length()-1]>='a'&&s[s.length()-1]<='z')    continue;
        }
        string a = s.substr(1,word.length());
        if(a.compare(word)==0){
            wed[idx].basic++;
        }
    }
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    for(int i=0; i<word.size(); i++){
        if(word[i]>='A'&&word[i]<='Z')  word[i] += 32;
    }
    for(int i=0; i<pages.size(); i++){
        for(int j=0; j<pages[i].size(); j++){
            if(pages[i][j]>='A'&&pages[i][j]<='Z')  pages[i][j] += 32;
        }
    }
    for(int i=0; i<pages.size(); i++){
        string s = "";
        for(int j=pages[i].find("<meta property=\"og:url\" content=\"")+33; j<pages[i].size(); j++){
            if(pages[i][j]=='\"') break;
            s += pages[i][j];
        }
        m[s] = i;
    }
    for(int i=0; i<pages.size(); i++){
        findWord(i, pages[i],word);
    }
    for(int i=0; i<pages.size(); i++){
        for(int j=0; j<wed[i].link.size(); j++){
            int idx = wed[i].link[j];
            wed[idx].linkPoint += wed[i].basic / wed[i].linkNum;
        }
    }
    double maxPoint = 0;
    for(int i=0; i<pages.size(); i++){
        wed[i].matching = wed[i].basic+wed[i].linkPoint;
        if(maxPoint<wed[i].matching){
            answer = i;
            maxPoint = wed[i].matching;
        }
    }
    return answer;
}