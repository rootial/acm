#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-12
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("F:\\code\\data\\solve_in.txt", "r", stdin);
#define out freopen("F:\\code\\data\\solve_out.txt", "w", stdout);
#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
//Steady tables

const int maxn = 2222;
const int MOD = (int)1e9;

int dp[maxn][maxn], sum[2][maxn];
LL f[maxn][maxn], g[2][maxn];

void pre() {
    dp[0][0] = sum[0][0] = 1;
    for (int i = 1; i <= 2000; i++)
        sum[0][i] = sum[0][i-1] + dp[0][i];

    for (int i = 1; i <= 2000; i++) {
        int now = i&1;
        int pre = now^1;
        dp[i][0] = sum[now][0] = 1;
        for (int j = 1; j <= 2000; j++) {
            dp[i][j] = sum[pre][j];
            sum[now][j] = (sum[now][j-1] + dp[i][j])%MOD;
        }
    }
}
int main() {
//    in
    int T;
    pre();

    for (int t = scanf("%d", &T); t <= T; t++) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= m; i++) {
            f[1][i] = dp[m][i];
            g[1][i] = ((i ? g[1][i-1] : 0) + f[1][i])%MOD;
        }
        for (int i = 2; i <= n; i++) {
            int now = i&1;
            int pre = now^1;

            for (int j = 0; j <= m; j++) {
                f[i][j] = g[pre][j] * dp[m][j] % MOD;

                g[now][j] = ((j ? g[now][j-1] : 0) + f[i][j])%MOD;
            }
        }
        printf("%lld\n", g[n&1][m]%MOD);
    }
    return 0;
}
