#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct _Node{
    int value;
    int x;
    _Node *left;
    _Node *right;
} Node;

Node node[10001];
vector<int> ans;

bool cmp(vector<int> &a, vector<int> &b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return b[1] < a[1];
}

void makeTree(Node *parent, Node *child){
    if(parent->x > child->x){
        if(parent->left == NULL){
            parent->left = child;
        }
        else{
            makeTree(parent->left, child);
        }
    }
    else{
        if(parent->right == NULL){
            parent->right = child;
        }
        else{
            makeTree(parent->right, child);
        }
    }
}

void preorder(Node* now){
    if(now == NULL) return;
    ans.push_back(now->value);
    preorder(now->left);
    preorder(now->right);
}

void postorder(Node* now){
    if(now == NULL) return;
    postorder(now->left);
    postorder(now->right);
    ans.push_back(now->value);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i=0; i<nodeinfo.size(); i++){
        node[i].x = nodeinfo[i][0];
        node[i].value = i+1;
        nodeinfo[i].push_back(i);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    Node *root = &node[nodeinfo[0][2]];
    for(int i=1; i<nodeinfo.size(); i++){
        makeTree(root, &node[nodeinfo[i][2]]);
    }
    preorder(root);
    answer.push_back(ans);
    ans.clear();
    postorder(root);
    answer.push_back(ans);
    return answer;
}