#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N              4
#define MAX_QUERYCOUNT 1000000

static int digits[N];
static int digits_c[10];

static int T;

typedef struct {
	int strike;
	int ball;
} Result;
 



static int querycount; 

// the value of limit_query will be changed in evaluation
static const int limit_query = 2520;

static bool isValid(int guess[]) {
	int guess_c[10];
	
	for (int count = 0; count < 10; ++count) guess_c[count] = 0;
	for (int idx = 0; idx < N; ++idx) {
		if (guess[idx] < 0 || guess[idx] >= 10 || guess_c[guess[idx]] > 0) return false;
		guess_c[guess[idx]]++;
	}
	return true;
}

// API : return a result for comparison with digits[] and guess[]
Result query(int guess[]) {
	Result result;
	
	if (querycount >= MAX_QUERYCOUNT) {
		result.strike = -1;
		result.ball = -1;
		return result;
	}
	
    querycount++;
		
	if (!isValid(guess)) {
		result.strike = -1;
		result.ball = -1;
		return result;
	}
	
	result.strike = 0;
	result.ball = 0;

	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] == digits[idx])
			result.strike++;
		else if (digits_c[guess[idx]] > 0)
			result.ball++;

	return result;
}

static void initialize() {
	for (int count = 0; count < 10; ++count) digits_c[count] = 0;
	for (int idx = 0; idx < N; ++idx) {
		char c;
		do scanf("%c", &c); while(c < '0' || c > '9');
		digits[idx] = c - '0';
		digits_c[digits[idx]]++;
	}
	
	querycount = 0;
}

static bool check(int guess[]) {
	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] != digits[idx]) return false;
	return true;
}

int num[9877] = {0,};
int str[5050] = {0,};
int flag = 0;
int cnt = 0;

Result cmp(int a, int b){
    Result res = {0, 0};
    int count[10] = {0,};
    for(int i=0; i<N; i++){
        if(a%10 == b%10)    res.strike++;
        else{
            count[a%10]++;
            count[b%10]++;
        }
        a = a/10;
        b = b/10;
    }
    for(int i=0; i<10; i++){
        if(count[i] == 2)   res.ball++;
    }
    return res;
}

void doUserImplementation(int guess[]){
    int now;
    cnt = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(i==j)    continue;
            for(int k=0; k<10; k++){
                if(i==k||j==k)  continue;
                for(int l=0; l<10; l++){
                    if(i==l||j==l||k==l)    continue;
                    str[cnt++] = i*1000+j*100+k*10+l;
                }
            }
        }
    }
    for(int i=0; i<cnt; i++)    num[str[i]] = 0;
    Result result1, result2;
    while(1){
        for(int i=0; i<cnt; i++){
            if(num[str[i]] == 0){
                now = str[i];
                guess[0] = now/1000;
                guess[1] = (now/100)%10;
                guess[2] = (now/10)%10;
                guess[3] = now%10;
                break;
            }
        }
        result1 = query(guess);
        if(result1.strike == 4) break;
        for(int i=0; i<cnt; i++){
            if(num[str[i]] == 0){
                result2 = cmp(now, str[i]);
                if(result1.strike == result2.strike && result1.ball == result2.ball)    continue;
                num[str[i]] = 1;
            }
        }
    }
}

int main() {
	int total_score = 0;
	int total_querycount = 0;;
	
    // freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++testcase) {
        initialize();

        int guess[N];
		doUserImplementation(guess);

		if (!check(guess)) querycount = MAX_QUERYCOUNT;
        if (querycount <= limit_query) total_score++;
		printf("#%d %d\n", testcase, querycount);
		total_querycount += querycount;
    }
	if (total_querycount > MAX_QUERYCOUNT) total_querycount = MAX_QUERYCOUNT;
	printf("total score = %d\ntotal query = %d\n", total_score * 100 / T, total_querycount);
	return 0;
}