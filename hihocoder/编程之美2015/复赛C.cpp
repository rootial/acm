
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-8
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("solve_in.txt", "r", stdin);
#define out freopen("solve_out.txt", "w", stdout);
#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x7f7f7f7f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int maxn = (int)1e5 + 10;
int cnt[20][20];
LL dp[1<<16|1];
int sum[20];

int main() {
//    in
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        int n, k;
        scanf("%d%d", &n, &k);
//        bug(n)
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);

        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            x--;
            for (int j = 0; j < k; j++) {
                if (j != x)
                cnt[j][x] += sum[j];
            }
            sum[x]++;
        }
        dp[0] = 0;
        for (int st = 1; st < (1<<k); st++) {
            dp[st] = (LL)1e15;
            for (int i = 0; i < k; i++) if (st&(1<<i)) {
                LL tmp = dp[st^(1<<i)];
                for (int j = 0; j < k; j++) if (st&(1<<j)) {
                    tmp += cnt[i][j];
                }
                dp[st] = min(dp[st], tmp);
            }
        }
        printf("Case #%d: %I64d\n", t, dp[(1<<k)-1]);
     }
    return 0;
}
