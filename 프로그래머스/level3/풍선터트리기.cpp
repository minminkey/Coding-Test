#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 2;
    int leftIdx = 0;
    int rightIdx = a.size()-1;
    int leftMin = a[0];
    int rightMin = a[rightIdx];
    while(leftIdx+1!=rightIdx){
        if(leftMin>rightMin){
            leftIdx++;
            if(a[leftIdx]<leftMin){
                answer++;
                leftMin = a[leftIdx];
            }    
        }  
        else{
            rightIdx--;
            if(a[rightIdx]<rightMin){
                answer++;
                rightMin = a[rightIdx];
            }
        }
    }
    return answer;
}