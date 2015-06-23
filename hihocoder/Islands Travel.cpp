#include<bits/stdc++.h>

#define  esp 1e-7
#define  pi acos(-1.0)
#define  pb push_back
#define  lson l, m, rt<<1
#define  rson m+1, r, rt<<1|1
#define  mp(a, b) make_pair((a), (b))
#define  in  freopen("solve_in.txt", "r", stdin);
#define  out freopen("out.txt", "w", stdout);
#define  print(a) printf("%d\n",(a));
#define  bug puts("********))))))");
#define  stop  system("pause");
#define  Rep(i, c) for(__typeof(c.end()) i = c.begin(); i != c.end(); i++)
#define  inf 0x0f0f0f0f
#define  pf(x) ((x)*(x))

using namespace std;
typedef long long  LL;
typedef vector<int> VI;
typedef pair<int,int> pii;
typedef vector<pii> VII;
typedef vector<pii, int> VIII;
typedef VI:: iterator IT;
typedef map<string, int> mpx;
typedef map<int, int> mpi;


const int maxn = 100000 + 10;
int dist[maxn];

struct Edge {
    int v, c;
    Edge() {}
    Edge(int v, int c):v(v), c(c) {}
};

struct HeapNode {
    int d, u;
    bool operator < (const HeapNode &rhs)const {
        return d > rhs.d;
    }
    HeapNode(int d, int u):d(d), u(u) {}
};
bool done[maxn];
vector<Edge> edges[maxn];
void dijkstra(int s) {
    priority_queue<HeapNode> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    memset(done, false, sizeof done);
    q.push(HeapNode(0, 0));
    while(!q.empty()) {
        HeapNode x = q.top();
        q.pop();
        int u = x.u;
        int ud = x.d;
        if(done[u])
            continue;
        done[u] = true;
        for(int i = 0; i < (int)edges[u].size(); i++) {
            int v = edges[u][i].v;
            int d = edges[u][i].c;
            if(dist[v] > 0LL + ud + d) {
                dist[v] = ud+d;
                q.push(HeapNode(dist[v], v));
            }
        }
    }
}
struct Node {
    int x, y, id;
    Node() {}
    Node(int x, int y, int id):x(x), y(y), id(id) {}
} p[maxn];
bool cmp1(const Node& a,const Node& b) {
    return a.x < b.x;
}
bool cmp2(const Node&a, const Node& b) {
    return a.y < b.y;
}
int main(void) {
//    in
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < maxn; i++)
            edges[i].clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].id = i;
        }
        sort(p, p+n, cmp1);
        for (int i = 0; i < n-1; i++) {
            int c = p[i+1].x-p[i].x;
//             assert(c >= 0);
            edges[p[i].id].push_back(Edge(p[i+1].id, c));
            edges[p[i+1].id].push_back(Edge(p[i].id, c));
        }
        sort(p, p+n, cmp2);
        for (int i = 0; i < n-1; i++) {
            int c = p[i+1].y-p[i].y;
//            assert(c >= 0);
            edges[p[i].id].push_back(Edge(p[i+1].id, c));
            edges[p[i+1].id].push_back(Edge(p[i].id, c));
        }
        dijkstra(0);
        printf("%d\n", dist[n-1]);
    }
    return 0;
}
