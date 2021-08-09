#include<iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = 0;
    for(int i=1; i<=count; i++){
        sum += price*i;
    }
    if(sum<money)   return 0;
    return sum-money;
}