#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int x;
    int value;
    struct Node *left;
    struct Node *right;
};
struct Node node[10001];

bool cmp(vector<int> a, vector<int> b){
    if(a[1]==b[1])  return a[0]<b[0];
    return a[1]>b[1];
}
void makeTree(struct Node *p, struct Node *c){
    if(p->x>c->x){
        if(p->left==NULL){
            p->left = c;
        }
        else{
            makeTree(p->left, c);
        }
    }
    else{
        if(p->right==NULL){
            p->right = c;
        }
        else{
            makeTree(p->right, c);
        }
    }
}
void preorder(vector<int> &ans, struct Node *now){
    if(!now)    return;
    ans.push_back(now->value);
    preorder(ans, now->left);
    preorder(ans, now->right);
}
void postorder(vector<int> &ans, struct Node *now){
    if(!now)    return;
    postorder(ans, now->left);
    postorder(ans, now->right);
    ans.push_back(now->value);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i=0; i<nodeinfo.size(); i++){
        nodeinfo[i].push_back(i+1);
        node[i+1].x = nodeinfo[i][0];
        node[i+1].value = i+1;
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    Node *root = &node[nodeinfo[0][2]];
    for(int i=1; i<nodeinfo.size(); i++){
        makeTree(root, &node[nodeinfo[i][2]]);
    }
    vector<int> t;
    preorder(t, root);
    answer.push_back(t);
    vector<int> t1;
    postorder(t1, root);
    answer.push_back(t1);
    return answer;
}