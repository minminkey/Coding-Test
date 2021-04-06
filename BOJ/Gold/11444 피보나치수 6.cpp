#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long, long> mp;

long long fibo(long long n){
   if(n==1) return 1;
   else if(n==2)  return 1;
   else if(mp[n])  return mp[n];
   else{
      if(n%2==0){
         long long tmp = n/2;
         long long a = fibo(tmp-1);
         long long b = fibo(tmp);
         mp[n] = (2*a+b)*b%1000000007;
      }
      else{
         long long tmp = (n+1)/2;
         long long a = fibo(tmp-1);
         long long b = fibo(tmp);
         mp[n] = (a*a+b*b)%1000000007;
      }
      return mp[n];
   }
}

int main(){
   long long n;
   cin>>n;
   cout<<fibo(n)<<'\n';
}