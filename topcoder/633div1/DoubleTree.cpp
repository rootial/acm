#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-14
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("solve_in.txt", "r", stdin);
#define bug(x) printf("Line : %u >>>>>>\n", (x));
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f
using namespace std;
typedef long long LL;
typedef unsigned US;
typedef pair<int, int> PII;
typedef map<PII, int> MPS;
typedef MPS::iterator IT;
const int maxn = 55;

int src, sink;

struct Edge {
    int u, v, c;
    Edge() {}
    Edge(int u, int v, int c):u(u), v(v), c(c) {}
};

struct MaxFlow {
    int n, m;
    vector<int> G[maxn];
    vector<Edge> edges;
    int Now[maxn], Dfn[maxn];

    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void add(int u, int v, int c) {
   // cout << u << ' ' << v << endl;
        edges.pb(Edge(u, v, c));
        edges.pb(Edge(v, u, 0));
        m = edges.size();
        G[u].pb(m-2);
        G[v].pb(m-1);
    }
    int ISAP(int s, int flow) {
        if(s == sink) return flow;
        int now = 0, vary, tab = n, v;
        for(int i = 0; i < (int)G[s].size(); i++) {
            Edge &e = edges[G[s][i]];
            if(e.c > 0) {
                if(Dfn[s] == Dfn[v = e.v] + 1)
                    vary = ISAP(v, min(flow-now, e.c)), now += vary,
                            e.c -= vary, edges[G[s][i]^1].c += vary;
                if(Dfn[src] == n) return now;
                if(e.c > 0) tab = min(tab, Dfn[v]);
                if(flow == now) break;
            }
          }
            if(now == 0) {
                if(--Now[Dfn[s]] == 0)
                    Dfn[src] = n;
                Now[Dfn[s] = tab+1]++;
            }

        return now;
    }
    int getAns() {
        memset(Now, 0, sizeof Now);
        memset(Dfn, 0, sizeof Dfn);
        Now[0] = n;
        int ans = 0;
        while(Dfn[src] < n)
            ans += ISAP(src, inf);
        return ans;
    }
} solver;

class DoubleTree {
public:
    int n;
    int g[maxn][maxn];
    vector<int> tree[2][maxn];
    int rt;
    void add(int id, int u, int v) {

        tree[id][u].pb(v);
        tree[id][v].pb(u);
    }
    void dfs(int id, int u, int fa) {
        if(fa != -1 && fa != rt) {
            g[u][fa] = 1;
        }
        for(int i = 0; i < sz(tree[id][u]); i++) {
            int v = tree[id][u][i];
            if(v == fa) continue;
            dfs(id, v, u);
        }
    }
    int maximalScore(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> s) {
        n = sz(a)+1;
        int mx, z;

        for(int i = 0; i < n-1; i++) {
            add(0, a[i], b[i]);
            add(1, c[i], d[i]);
        }
        int ans = 0;
        src = n, sink = n+1;

        for(int i = 0; i < n; i++ ){
            mx = z = 0;
            memset(g, 0, sizeof g);

            for(int j = 0; j < n; j++) {
                mx += (i != j ? abs(s[j]) : 0);
                z += (i != j && s[j] > 0 ? s[j] : 0);
            }
            mx+=10;
            rt = i;
            dfs(0, i, -1);
            dfs(1, i, -1);
             //for(int ii = 0; ii < n; ii++, puts("")) for(int j = 0; j < n; j++)
         //  cout << g[ii][j] << ' ';
            solver.init(n+2);
            for(int u = 0; u < n; u++) {
                if(u != rt) {
                    if(s[u] > 0) solver.add(src, u, s[u]);
                    else solver.add(u, sink, -s[u]);
                }
                for(int v = 0; v < n; v++) {
                    if(!g[u][v]) continue;
                    solver.add(u, v, mx);
                }
            }

            ans = max(ans, z-solver.getAns()+s[i]);
        }
        return ans;
    }
};
int main(){
    return 0;
}


// Powered by FileEdit
