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

#define IN freopen("express.in", "r", stdin);
#define OUT freopen("express.out", "w", stdout);

#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int maxn = 2000 + 10;
vector<int> g[maxn];
int dp[maxn][maxn];
PII pa[maxn][maxn];
int a, b, c, d;

int dfs(int x, int y) {
    int &res = dp[x][y];
    if (~res) return res;
    res = 0;
    if ((x < y || y == d) && x != b) {
        for (int i = 0; i < (int)g[x].size(); i++) {
            int c = g[x][i];
            if (c != y) {
                res |= dfs(c, y);
                if (res) {
                    pa[x][y] = PII(c, y);
                    return res;
                }
            }
        }
    } else if ((x > y || x == b) && y != d) {
        for (int i = 0; i < (int)g[y].size(); i++) {
            int c = g[y][i];
            if (c != x) {
                res |= dfs(x, c);
                if (res) {
                    pa[x][y] = PII(x, c);
                    return res;
                }
            }
        }
    }
    return res;
}
int main() {
    IN
    OUT
//    in
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cin >> a >> b >> c >> d;
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        g[u].push_back(v);
    }
    dp[b][d] = 1;
    vector<int> p1, p2;
    p1.push_back(a);
    p2.push_back(c);
    if (dfs(a, c)) {
        puts("YES");
        while (a != b || c != d) {
            int na = pa[a][c].first;
            int nc = pa[a][c].second;
            if (na != a) {
                p1.push_back(na);
                a = na;
            }
            if (nc != c) {
                p2.push_back(nc);
                c = nc;
            }
        }
        for (int i = 0; i < (int)p1.size(); i++) {
            printf("%d%c", p1[i], i == (int)p1.size()-1 ? '\n' : ' ');
        }
        for (int i = 0; i < (int)p2.size(); i++) {
            printf("%d%c", p2[i], i == (int)p2.size()-1 ? '\n' : ' ');
        }
    } else {
        puts("NO");
    }
    return 0;
}
