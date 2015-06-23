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

#define IN freopen("solid.in", "r", stdin);
#define OUT freopen("solid.out", "w", stdout);

#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int maxn = 20;
LL dp[maxn][(1<<8)+10][(1<<8)];
int n, m, all;

void dfs(int pos, int st0, int st1, int cur, int nst0, int nst1) {
    if (cur == m) {
        if (pos+1 != n && nst0 == 0) return;
//        if (pos+1 == n && nst0 == 0 )
//        bug(dp[pos][st0][st1])
        dp[pos+1][nst0][nst1] += dp[pos][st0][st1];
        return;
    }
    int mask = st0&(1<<cur);
    if (mask == 0) {
        if (cur + 1 < m && (st0&(1<<(cur+1))) == 0) {
            dfs(pos, st0, st1, cur+2, nst0, nst1|(1<<cur));
        }
        dfs(pos, st0, st1, cur+1, nst0|(1<<cur), nst1);
    } else {
        dfs(pos, st0, st1, cur+1, nst0, nst1);
    }
}
int main() {
//    in
IN
OUT
    cin >> m >> n;
    if (n*m%2) {
        puts("0");
        return 0;
    }
    all = (1<<m);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int st0 = 0; st0 < all; st0++)
            for (int st1 = 0; st1 < all/2; st1++) {
                if (!dp[i][st0][st1]) continue;
                dfs(i, st0, st1, 0, 0, st1);
            }
    }
    cout << dp[n][0][all/2-1] << endl;
    return 0;
}
