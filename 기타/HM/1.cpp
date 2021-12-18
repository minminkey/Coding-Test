#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<string> units, vector<long long> numbers) {
    long long answer = 0;
    map<string, long long> dic;
    long long x = 1024;
    dic["B"] = 1;
    dic["KB"] = x;
    dic["MB"] = x*x;
    dic["GB"] = x*x*x;
    dic["TB"] = x*x*x*x;
    for(int i=0; i<units.size(); i++){
        answer += dic[units[i]] * numbers[i];
    }
    return answer;
}