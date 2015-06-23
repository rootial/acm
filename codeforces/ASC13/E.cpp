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

#define IN freopen("path.in", "r", stdin);
#define OUT freopen("path.out", "w", stdout);

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

bool inCir[maxn], vis[maxn], inq[maxn];
int num[maxn];
LL dist[maxn];

int n, m, st;
struct Edge {
    int u, v;
    LL c;
    Edge() {}
    Edge(int u, int v, LL c):u(u), v(v), c(c) {}
};
vector<Edge> edges;
vector<int> G[maxn];

void add(int u, int v, LL c) {
    edges.push_back(Edge(u, v, c));
    G[u].push_back((int)edges.size()-1);
}
void spfa(int s) {

    for (int i = 1; i <= n; i++)
        dist[i] = (LL)5e18;
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < (int)G[u].size(); i++) {
            Edge e = edges[G[u][i]];
            int v = e.v;
            if (dist[v] > dist[u] + e.c) {
                dist[v] = dist[u] + e.c;
                if (!inq[v]) {
                    if (++num[v] > n) {
                        inCir[v] = true;
                    } else {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
    }
}
void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < (int)G[u].size(); i++) {
        Edge e = edges[G[u][i]];
        int  v = e.v;
        if (vis[v]) continue;
        dfs(v);
    }
}
int main() {
IN
OUT
    cin >> n >> m >> st;
    for (int i = 0; i < m; i++) {
        int u, v;
        LL c;
        scanf("%d%d%I64d", &u, &v, &c);
        add(u, v, c);
    }
    spfa(st);
    for (int i = 1; i <= n; i++) {
        if (inCir[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            puts("-");
        } else if (dist[i] == (LL)5e18) {
            puts("*");
        } else {
            printf("%I64d\n", dist[i]);
        }
    }
    return 0;
}
