#include<bits/stdc++.h>
#define in freopen("F:\\code\\data\\oo.in", "r", stdin);

#define out freopen("F:\\code\\data\\solve_out.txt", "w", stdout);
#define inf 0x0f0f0f0f
using namespace std;
const int maxn = 9000;
typedef map<string, int> MPS;
MPS mps;

vector<int> ma[222];
char s[22222];
int cnt;
int id(string str) {
    if (!mps.count(str)) {
        mps[str] = cnt++;
    }
    return mps[str];
}
struct Edge {
    int u, v, c;
    Edge() {}
    Edge(int u, int v, int c):u(u), v(v), c(c) {}
};
struct MaxFlow {
    int n, m, src, sink;

    int Dfn[maxn], Now[maxn];
    vector<Edge> edges;
    vector<int>G[maxn];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < maxn; i++)
            G[i].clear();
        edges.clear();
    }
    void add(int u, int v, int c) {
        edges.push_back(Edge(u, v, c));
        edges.push_back(Edge(v, u, 0));
        int mm = (int)edges.size();
        G[u].push_back(mm-2);
        G[v].push_back(mm-1);
    }
    int ISAP(int s, int flow) {
        if (s == sink) {
            return flow;
        }
        int vary, now = 0, tab = n;
        for (int i = 0; i < (int)G[s].size(); i++) {
            Edge &e = edges[G[s][i]];
            int v;
            if (e.c > 0) {
                if (Dfn[s] == Dfn[v = e.v] + 1)
                    vary = ISAP(v, min(e.c, flow-now)), now += vary,
                            e.c -= vary, edges[G[s][i]^1].c += vary;
                if (Dfn[src] == n) return now;
                if (e.c > 0) tab = min(tab, Dfn[v]);
                if (now == flow) break;
            }
        }
        if (now == 0) {
            if (--Now[Dfn[s]] == 0) {
                Dfn[src] = n;
            }
            Now[Dfn[s] = tab + 1]++;
        }
        return now;
    }
    int getAns(int src, int sink) {
        this->src = src;
        this->sink = sink;
        memset(Dfn, 0, sizeof Dfn);
        memset(Now, 0, sizeof Now);
        Now[0] = n;
        int ans = 0;
        while (Dfn[src] < n) {
            ans += ISAP(src, (int)1e9);
        }
        return ans;
    }
} solver;
int main() {
    in
    out
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        int n;
        cin >> n;
//        cout << n << endl;
        cnt = 0;
        gets(s);
        mps.clear();
        for (int i = 0; i < n; i++) {
            ma[i].clear();
            gets(s);
            stringstream ss(s);
            string str;
            while (ss >> str) {
                ma[i].push_back(id(str));
            }
        }
        int src = 2*n+2*cnt;
        int sink = 2*n+2*cnt+1;

        solver.init(2*n+2*cnt+2);
        solver.add(src, 0, 10000000);
        solver.add(3, sink, 10000000);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)ma[i].size(); j++) {
                int ID = ma[i][j];
                solver.add(2*i, 2*n+2*ID, 10000000);
                solver.add(2*n+2*ID+1, 2*i+1, 10000000);
            }
            solver.add(2*i, 2*i+1, 10000000);
            if (i > 1) {
                solver.add(src, 2*i, 10000);
                solver.add(2*i+1, sink, 10000);
            }
        }
        for (int i = 0; i < cnt; i++)
            solver.add(2*n+2*i, 2*n+2*i+1, 1);
        int ans = solver.getAns(src, sink)-(n-2)*10000;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
