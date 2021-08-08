#define MAX_N 1000
#define MAX_M 20

int N, M;
int board[MAX_N][MAX_N];
int br[20001];
int bc[20001];
int visit[20001];
int cnt;
int star[4][MAX_M][MAX_M];
int sr[4];
int sc[4];

struct Result {
    int y, x;
};

void init(int n, int m, int Map[MAX_N][MAX_N])
{
    N = n;
    M = m;
    cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = Map[i][j];
            if (board[i][j] == 1) {
                br[cnt] = i;
                bc[cnt] = j;
                visit[cnt] = 0;
                cnt++;
            }
        }
    }
}


Result findConstellation(int stars[MAX_M][MAX_M])
{
    Result res;
    res.y = res.x = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            star[0][i][j] = stars[i][j];
            if (star[0][i][j] == 9) {
                sr[0] = i;
                sc[0] = j;
            }
        }
    }
    for (int d = 1; d < 4; d++) {
        int i, j;
        j = 0;
        for (int r = 0; r < M; r++) {
            i = M - 1;
            for (int c = 0; c < M; c++) {
                star[d][r][c] = star[d - 1][i][j];
                if (star[d][r][c] == 9) {
                    sr[d] = r;
                    sc[d] = c;
                }
                i--;
            }
            j++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int d = 0; d < 4; d++) {
            if (visit[i] == 1)    continue;
            int str = br[i] - sr[d];
            int stc = bc[i] - sc[d];
            if (str < 0 || stc < 0 || str + M-1 >= N || stc + M-1 >= N)    continue;
            int flag = 0;
            for (int r = 0; r < M; r++) {
                for (int c = 0; c < M; c++) {
                    if (star[d][r][c] != 0 && board[str + r][stc + c] == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag)    break;
            }
            if (!flag) {
                visit[i] = 1;
                res.y = br[i];
                res.x = bc[i];
                return res;
            }
        }
    }
    return res;
}
