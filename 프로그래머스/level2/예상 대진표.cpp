#include <iostream>
#include <vector>

using namespace std;

int A, B;
int Answer;
vector<int> battle(vector<int> part){
    vector<int> tmp;
    Answer++;
    for(int i=0; i<part.size()-1; i += 2){
            // cout<<part[i]<<' '<<part[i+1]<<endl;
        if((part[i]==A&&part[i+1]==B)||(part[i]==B&&part[i+1]==A)){
            tmp.clear();
            return tmp;
        }
        else if(part[i]==A||part[i+1]==A)    tmp.push_back(A);
        else if(part[i]==B||part[i+1]==B)    tmp.push_back(B);
        else                                 tmp.push_back(part[i]);
    }
    return tmp;
}

int solution(int n, int a, int b)
{
    int answer = 3;
    A = a;
    B = b;
    vector<int> part;
    for(int i=1; i<=n; i++){
        part.push_back(i);
    }
    while(part.size()>1){
        part = battle(part);
    }
    answer = Answer;
    return answer;
}