#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int Max=-2147483648;
int N;
string s;
int opsize;
vector<int> numbers;
vector<char> op;

int cal(int a, int b, char c){
    if(c == '+')    return a+b;
    else if(c == '-')   return a-b;
    else            return a*b;
}
void calculater(vector<int> order){
    vector<int>::iterator it;
    vector<int> resultNumber;
    vector<char> resultOp;
    // for(int i=0; i<order.size(); i++){
    //     cout<<order[i]<<' ';
    // }
    // cout<<endl;
    // for(int i=0; i<numbers.size(); i++){
    //     cout<<numbers[i]<<' ';
    // }
    // cout<<endl;
    sort(order.begin(), order.end(), greater<int>());
    for(int i=0; i<s.size(); i++){
        if(!order.empty()&&i==order.back()*2){
            order.pop_back();
            // cout<<i<<endl;
            int result = cal(numbers[i/2], numbers[i/2+1], s[i+1]);
            // cout<<"reuslt : "<<result<<' '<<numbers[i/2]<<' '<<numbers[i/2+1]<<endl;
            resultNumber.push_back(result);
            i = i+2;
        }
        else{
            if(s[i]>='0'&&s[i]<='9'){
                resultNumber.push_back(s[i]-'0');
            }
            else{
                resultOp.push_back(s[i]);
            }
        }
    }
    int now = resultNumber[0];
    // cout<<now<<endl;
    int idx = 0;
    for(int i=1; i<resultNumber.size(); i++){
        // cout<<now<<' '<<resultOp[idx]<<' '<<resultNumber[i]<<endl;;
        now = cal(now, resultNumber[i], resultOp[idx++]);
    }
    // cout<<now<<endl;
    if(Max<now) Max = now;
}
void dfs(vector<int> order){
    calculater(order);
    // for(int i=0; i<order.size(); i++){
    //     cout<<order[i]<<' ';
    // }
    // cout<<endl;
    if(order.back()+2>=opsize){
        return;
    }
    for(int i=order.back()+2; i<opsize; i++){
        order.push_back(i);
        dfs(order);
        order.pop_back();
    }
    return;
}
int main(){
    cin>>N;
    cin>>s;
    if(N==1){
        cout<<s<<endl;
        return 0;
    }
    opsize = (N-1)/2;
    vector<int> order;
    for(int i=0; i<N; i++){
        if(s[i]>='0'&&s[i]<='9'){
            numbers.push_back(s[i]-'0');
        }
        else{
            op.push_back(s[i]);
        }
    }
    for(int i=0; i<op.size(); i++){
        order.push_back(i);
        dfs(order);
        order.pop_back();
    }
    cout<<Max<<endl;
}