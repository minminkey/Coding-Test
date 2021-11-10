#include <string>
#include <vector>

using namespace std;
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 10e5 * 4 * 10e9;

    long long start = 0;
    long long end = 10e5 * 4 * 10e9;

    while (start <= end) {
        long long mid = (start + end) / 2;

        long long gold_carry = 0;
        long long sil_carry = 0;
        long long add_carry = 0;

        for (int i = 0; i < s.size(); i++) {
            long long now_gold = (long long)g[i];
            long long now_sil = (long long)s[i];
            long long now_w = (long long)w[i];
            long long now_t = (long long)t[i];

            long long move_cnt = mid / (now_t * 2);
            if (mid % (now_t * 2) >= t[i]) move_cnt++; //편도로 1번더 갈 수 있다면 1회 추가

            gold_carry += (now_gold < move_cnt* now_w) ? now_gold : move_cnt * now_w;
            sil_carry += (now_sil < move_cnt* now_w) ? now_sil : move_cnt * now_w;
            add_carry += (now_gold + now_sil < move_cnt* now_w) ? now_gold + now_sil : move_cnt * now_w;

        }

        if (gold_carry >= a && sil_carry >= b && add_carry >= a + b) {
            end = mid - 1;
            answer = min(mid, answer);
        }
        else {
            start = mid + 1;
        }

    }

    return answer;
}