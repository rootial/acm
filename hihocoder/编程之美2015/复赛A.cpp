
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
const int maxn = 100000 + 10;
int sum[maxn], a[maxn];
LL ans;
vector<int> g[maxn];

void dfs(int u, int fa, int dep) {
    sum[u] = a[u];
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa ) continue;
        dfs(v, u, dep+1);
        sum[u] += sum[v];
    }
    if (fa)
    ans = max(ans, sum[u] - 1LL + dep);
}
int main() {
//    in
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        int n, s;
        scanf("%d%d", &n ,&s);
        ans = 0;
        for (int i = 0; i < maxn; i++) g[i].clear();

        for (int i = 0; i < n-1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", a+i);
        }
        dfs(s, 0, 0);
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
