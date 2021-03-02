#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> tg;
    vector<char> op;
    stack<int> st;
    int flag = 0;
    int flag2 = 0;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += s[i];
        }
        else if (s[i] == '*' || s[i] == '/')
        {
            while (!st.empty() && (st.top() == '*' || st.top() == '/'))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << '\n';
    return 0;
}