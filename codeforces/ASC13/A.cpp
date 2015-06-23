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

#define IN freopen("assignment.in", "r", stdin);
#define OUT freopen("assignment.out", "w", stdout);

#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int maxn = 110;
struct Edge {
    int u, v, cap, cost;
    Edge() {}
    Edge(int u, int v, int cap, int cost):u(u), v(v), cap(cap), cost(cost) {}
};

struct MCMF {
    int n, m;
    vector<int> G[maxn];
    vector<Edge> edges;
    int dist[maxn];
    int pa[maxn];
    bool inq[maxn];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void add(int u, int v, int cap, int cost) {
        edges.push_back(Edge(u, v, cap, cost));
        edges.push_back(Edge(v, u, 0, -cost));
        int mm = (int)edges.size();
        G[u].push_back(mm-2);
        G[v].push_back(mm-1);
    }
    bool spfa(int s, int t) {
        memset(dist, 0x0f, sizeof dist);
        memset(inq, false, sizeof inq);
        memset(pa, -1, sizeof pa);

        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int i = 0; i < (int)G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                int v = e.v;
                if (e.cap > 0 && dist[v] > dist[u] + e.cost) {
                    dist[v] = dist[u] + e.cost;
                    pa[v] = G[u][i];
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
        return dist[t] < inf;
    }
    int getAns (int src, int sink) {
        int ans = 0;
        int f = 0;
        while (spfa(src, sink)) {
            int cost = dist[sink];
            int flow = inf;
            int s = sink;
            while (s != src) {
                flow = min(flow, edges[pa[s]].cap);
                s = edges[pa[s]].u;
            }
            s = sink;
            while (s != src) {
                edges[pa[s]].cap -= flow;
                edges[pa[s]^1].cap += flow;
                s = edges[pa[s]].u;
            }
//            cout << cost << endl;
            ans += cost * flow;
            f += flow;
        }
//        bug(f)
        return ans;
    }
} solver;

int main() {
//    in
IN
OUT
    int n, k;
    scanf("%d%d", &n, &k);
    solver.init(2*n+2);
    int src = 2*n, sink = 2*n+1;

    for (int i = 0; i < n; i++) {
        solver.add(src, i, k, 0);
        solver.add(n+i, sink, k, 0);
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            solver.add(i, n+j, 1, x);
        }
    }
    printf("%d\n", solver.getAns(src, sink));
    return 0;
}
