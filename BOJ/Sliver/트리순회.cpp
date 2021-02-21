#include <iostream>
using namespace std;

struct Node
{
    int n, l, r;
};
struct Node node[30];

void preorder(int n)
{
    char p = 'A' + n;
    cout << p;
    if (node[n].l != -1)
        preorder(node[n].l);
    if (node[n].r != -1)
        preorder(node[n].r);
}
void midorder(int n)
{
    if (node[n].l != -1)
        midorder(node[n].l);
    char p = 'A' + n;
    cout << p;
    if (node[n].r != -1)
        midorder(node[n].r);
}
void postorder(int n)
{
    if (node[n].l != -1)
        postorder(node[n].l);
    if (node[n].r != -1)
        postorder(node[n].r);
    char p = 'A' + n;
    cout << p;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        int p = a - 'A';
        if (b == '.')
            node[p].l = -1;
        else
            node[p].l = b - 'A';
        if (c == '.')
            node[p].r = -1;
        else
            node[p].r = c - 'A';
    }
    preorder(0);
    cout << '\n';
    midorder(0);
    cout << '\n';
    postorder(0);
}
