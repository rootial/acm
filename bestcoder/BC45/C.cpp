#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>

#define pb push_back
#define mp make_pair
#define esp 1e-12
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#define in freopen("F:\\code\\data\\solve_in.txt", "r", stdin);
#define out freopen("F:\\code\\data\\solve_out.txt", "w", stdout);
#pragma comment(linker, "/STACK:102400000,102400000")
#define IN freopen("tickets.in", "r", stdin);
#define OUT freopen("tickets.out", "w", stdout);

#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int maxn = (int)1e5 + 10;
vector<int> g[maxn];
int a[maxn], pa[maxn][22], lid[maxn], rid[maxn], dep[maxn], sum[maxn];
int cnt, n;

void update(int x, int c) {
    while (x <= n) {
        sum[x] ^= c;
        x += lowbit(x);
    }
}
int query(int x) {
    int res = 0;
    while (x > 0) {
        res ^= sum[x];
        x -= lowbit(x);
    }
    return res;
}
void dfs1(int u, int fa) {
    pa[u][0] = fa;
    lid[u] = ++cnt;
    rid[u] = cnt;
    dep[u] = dep[fa] + 1;

    for (int i = 1; i < 20; i++) {
        pa[u][i] = pa[pa[u][i-1]][i-1];
    }

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs1(v, u);
        rid[u] = max(rid[u], rid[v]);
    }
}
int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int i = 0; i < 20; i++) {
        if (d&(1<<i)) {
            u = pa[u][i];
        }
    }
    if (u != v) {
        for (int i = 19; i >= 0; i--) if (pa[u][i] != pa[v][i]) {
                u = pa[u][i];
                v = pa[v][i];
            }
        u = pa[u][0];
    }
    return u;
}
int main() {
//    in
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        int q;
        cnt = 0;
        memset(sum, 0, sizeof sum);
        for (int i = 0; i < maxn; i++) {
            g[i].clear();
        }
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(1, 0);

        for (int i = 1; i <= n; i++) {
            scanf("%d", a+i);
            a[i]++;
            update(i, a[i]);
        }
        while (q--) {
            int u, v, op;
            scanf("%d%d%d", &op, &u, &v);
            if (op == 1) {
                int lca = LCA(u, v);
                int val0 = query(u);
                int val1 = query(v);

                printf("%d\n", (val0^val1^a[lca])-1);
            } else {
                v++;
                int delta = a[u]^v;

                a[u] = v;
                update(lid[u], delta);
                update(rid[u]+1, delta);
            }
        }
    }
    return 0;
}
