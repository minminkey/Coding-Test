#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

double ccw (double x1, double y1, double x2, double y2, double x3, double y3){
   double a = x1*y2 + x2*y3 + x3*y1;
   double b = y1*x2 + y2*x3 + y3*x1;
   return (a - b)/2;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   vector<double> x;
   vector<double> y;
   for(int i=0; i<n; i++){
      double a,b;
      cin>>a>>b;
      x.push_back(a);
      y.push_back(b);
   }
   double sum = 0;
   for(int i=1; i<n; i++){
      sum += ccw(x[0], y[0], x[i-1], y[i-1], x[i], y[i]);
   }
   // cout<<sum<<endl;
   sum = abs(sum);
   printf("%.1f\n", sum);
   // cout<<sum/10<<'\n';
   return 0;
}
