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

#define IN freopen("tickets.in", "r", stdin);
#define OUT freopen("tickets.out", "w", stdout);

#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<string, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int maxn = 500 + 10;
const int maxm = (int)4e4 + 2000;

MPS mps;
int cnt = 0;
int id(string s) {
    if (!mps.count(s)) {
        mps[s] = cnt++;
    }
    return mps[s];
}
int x[maxn], y[maxn];
int vis[2][maxn*2];
vector<int> ans[maxn];
vector<int> g[maxm];

struct Edge {
    int u, v, id;
    Edge() {}
    Edge(int u, int v, int id):u(u), v(v), id(id) {}
};
vector<Edge> edges;
void add(int u, int v, int id) {
    edges.push_back(Edge(u, v, id));
    edges.push_back(Edge(v, u, id));
    int mm = (int)edges.size();
    g[u].push_back(mm-2);
    g[v].push_back(mm-1);
}
PII has[maxn];
bool found[maxn];

const int N = (int)4e4 + 2000;
const int M = (int)4e4 + 10;



int first[N],Next[M],ver[M],tot;
PII which[M];
int linkx[N],linky[N], linke[N];
int dx[N],dy[N];
int n;//此处n为左边的点数
int ansa;
queue<int> q;
void add(int x,int y, int u, int v) {
//    cout << x
    if (!linkx[x]&&!linky[y]) {
        linkx[x]=y;
        linky[y]=x;
        linke[x]=tot+1;
        ansa++;
    }
//    cout << x << y << endl;
    ver[++tot]=y;
    which[tot] = PII(u, v);
    Next[tot]=first[x];
    first[x]=tot;
}

bool match(int x) {
    for (int p=first[x]; p; p=Next[p])
        if (dy[ver[p]]==dx[x]+1) {
            dy[ver[p]]=0;
            if (linky[ver[p]] == 0 ||match(linky[ver[p]])) {
                linky[ver[p]]=x;
                linkx[x]=ver[p];
                linke[x]=p;
                return true;
            }
        }
    return false;
}

bool bfs() {
    bool flag=false;
    memset(dx,0,sizeof dx);
    memset(dy,0,sizeof dy);
    for (int i=1; i<=n; i++)
        if (linkx[i]== 0)
            q.push(i);
    int x,y;
    while (!q.empty()) {
        x=q.front();
        q.pop();
        for (int p=first[x]; p; p=Next[p])
            if (dy[ver[p]]==0) {
                y=ver[p];
                dy[y]=dx[x]+1;
                if (linky[y]==0)
                    flag=true;
                else {
                    dx[linky[y]]=dx[x]+2;
                    q.push(linky[y]);
                }
            }
    }
    return flag;
}

int solve() {
    while (bfs())
        for (int i=1; i<=n; i++)
            if (linkx[i]==0&&match(i))
                ansa++;
    return ansa;
}



int main() {
//    in
//    int n, m;

IN
OUT
    int m;
    scanf("%d%d", &n, &m);
    char ch;
    while ((ch = getchar()) != '\n') {}
    bool ok = true;
    memset(vis, -1, sizeof vis);
    memset(found, false, sizeof false);
    int lim;
    for (int i = 0; i < n+m; i++) {
        string str = "";
        int xx, yy;
        if (i == n) {
            lim = cnt;
        }
        while ((ch = getchar()) != ',') {
            str += ch;
        }
        xx = id(str);
//        cout << str;
        str = "";
        while ((ch = getchar()) == ' ') {}
        str += ch;
        while ((ch = getchar()) != '\n' && ch != -1) {
            str += ch;
        }

        yy = id(str);
        if (i < n) {
            x[i] = xx;
            y[i] = yy;
            vis[0][xx] = i;
            if (vis[1][yy] != -1) {
                ok = false;
            }
            vis[1][yy] = i;
        } else {
            add(xx, yy, i-n);
        }
    }
//    bug()
    if (!ok) {
        puts("NO");
        return 0;
    }
    for (int i = 0; i < m*2; i += 2) {
        Edge e = edges[i];
        int u = e.u;
        int v = e.v;
        int c = e.id;
        if (u >= lim || v >= lim) continue;

        if (vis[0][u] != -1 && vis[0][u] == vis[1][v]) {
            ans[vis[0][u]].push_back(c);
            found[vis[0][u]] = true;
        } else if(vis[0][v] != -1 && vis[0][v] == vis[1][u]) {
            ans[vis[0][v]].push_back(c);
            found[vis[0][v]] = true;
        }
    }
    int mat = n-accumulate(found, found+n, 0);

    for (int i = 0; i < cnt; i++) {
        if (i < lim && (vis[0][i] != -1 || vis[1][i] != -1)) continue;
        memset(has, -1, sizeof has);

        for (int j = 0; j < (int)g[i].size(); j++) {
            Edge e = edges[g[i][j]];

            int v = e.v;
            int c = e.id;
            if (v >= lim) continue;
            if (vis[0][v] != -1) {
                has[vis[0][v]].first = c;
            }
            if (vis[1][v] != -1) {
                has[vis[1][v]].second = c;
            }
        }
        for (int j = 0; j < n; j++) {
            if (found[j]) continue;
            if (has[j].first != -1 && has[j].second != -1) {
                add(j+1, i+1, has[j].first, has[j].second);
            }
        }
    }
    int tmp = solve();
    if (tmp == mat) {

        puts("YES");
        for (int j = 0; j < n; j++) {
            if (found[j]) continue;
            int x = linke[j+1];
            ans[j].push_back(which[x].first);
            ans[j].push_back(which[x].second);
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", (int)ans[i].size());
            for (int j = 0; j < (int)ans[i].size(); j++) {
                printf("%d%c", ans[i][j]+1, j == (int)ans[i].size()-1 ? '\n' : ' ');
            }
        }
    } else {
        puts("NO");
    }
    return 0;
}

