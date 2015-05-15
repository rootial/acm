
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
const int maxn =  200000 + 10;
int ans[maxn];

void input(int &res) {
    res = 0;
    char ch;
    while ((ch = getchar()) < '0' || ch > '9') ;
    res = (int)(ch - '0');
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (int)(ch - '0');
}
struct Query {
    int id, l, r, val;
    Query() {}
    Query(int id, int l, int r, int val):id(id), l(l), r(r), val(val) {}
} q[maxn];
struct Node {
    int id, val;
    Node() {}
    Node(int id, int val):id(id), val(val) {}
} a[maxn];
bool cmp11(const Node &a, const Node &b) {
    return a.val > b.val;
}
bool cmp12(const Node &a, const Node &b) {
    return a.val < b.val;
}
bool cmp21(const Query &a, const Query &b) {
    return a.val > b.val;
}
bool cmp22(const Query &a, const Query &b) {
    return a.val < b.val;
}
int mi[2][maxn<<2];
void build(int l, int r, int rt, int c) {
    if (l == r) {
        mi[c][rt] = c ? -inf : inf;
        return;
    }
    int m = (l+r)>>1;
    build(lson, c);
    build(rson, c);
    if (!c) {
        mi[c][rt] = min(mi[c][rt<<1], mi[c][rt<<1|1]);
    } else {
        mi[c][rt] = max(mi[c][rt<<1], mi[c][rt<<1|1]);
    }
}
void update(int l, int r, int rt, int pos, int val, int c) {
    if (l == r) {
        mi[c][rt] = val;
        return;
    }
    int m = (l+r)>>1;
    if (pos <= m) {
        update(lson, pos, val, c);
    } else {
        update(rson, pos, val, c);
    }
    if (!c) {
        mi[c][rt] = min(mi[c][rt<<1], mi[c][rt<<1|1]);
    } else {
        mi[c][rt] = max(mi[c][rt<<1], mi[c][rt<<1|1]);
    }
}
int query(int l, int r, int rt, int L, int R, int c) {
    if (L <= l && R >= r) {
        return mi[c][rt];
    }
    int m = (l+r)>>1;
    int ans = c ? -inf : inf;
    if (L <= m) {
        ans = !c ? min(ans, query(lson, L, R, c)) : max(ans, query(lson, L, R, c));
    }
    if (R > m) {
        ans = !c ? min(ans, query(rson, L, R, c)) : max(ans, query(rson, L, R, c));
    }
    return ans;
}
int main() {
//    in
    int T;
//    cout << inf << endl;
    for (int t = scanf("%d", &T); t <= T; t++) {
        printf("Case #%d:\n", t);
        int n, m;
        scanf("%d%d", &n, &m);
        memset(ans, 0x7f, sizeof ans);
        for (int i = 1; i <= n; i++) {
            input(a[i].val);
            a[i].id = i;
        }
        for (int i = 1; i <= m; i++) {
            input(q[i].l);
            input(q[i].r);
            input(q[i].val);
            q[i].id = i;
        }
        sort(a+1, a+n+1, cmp11);
        sort(q+1, q+m+1, cmp21);
        build(1, n, 1, 0);

        int j = 1;
        for (int i = 1; i <= m; i++) {
            while (j <= n && a[j].val >= q[i].val) {
                update(1, n, 1, a[j].id, a[j].val, 0);
                j++;
            }
            int res = query(1, n, 1, q[i].l, q[i].r, 0);
//            bug(res)
            if (res >= q[i].val && res < inf) ans[q[i].id] = min(ans[q[i].id], res - q[i].val);
        }

        sort(a+1, a+n+1, cmp12);
        sort(q+1, q+m+1, cmp22);
        build(1, n, 1, 1);
        j = 1;
        for (int i = 1; i <= m; i++) {
            while (j <= n && a[j].val < q[i].val) {
                update(1, n, 1, a[j].id, a[j].val, 1);
                j++;
            }
            int res = query(1, n, 1, q[i].l, q[i].r, 1);
            if (res < q[i].val && res > -inf) ans[q[i].id] = min(ans[q[i].id], q[i].val - res);
        }
        for (int i = 1; i <= m; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
