#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int inorder[100001];
int postorder[100001];
int idx[100001];

void preorder(int ins, int ine, int ps, int pe){
   if(ins>ine||ps>pe)   return;
   int r = postorder[pe];
   cout<<r<<' ';
   preorder(ins, idx[r]-1, ps, ps+idx[r]-ins-1);
   preorder(idx[r]+1, ine, ps+idx[r]-ins, pe-1);
}

int main(){
   int n;
   cin>>n;
   int tmp;
   for(int i=0; i<n; i++){
      cin>>tmp;
      inorder[i] = tmp;
   }
   for(int i=0; i<n; i++){
      cin>>tmp;
      postorder[i] = tmp;
   }
   for(int i=0; i<n; i++){
      idx[inorder[i]] = i;
   }
   preorder(0,n-1,0,n-1);
   cout<<'\n';
   return 0;
}
