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
#define in freopen("F:\\code\\data\\oo.in", "r", stdin);
#define out freopen("F:\\code\\data\\solve_out.txt", "w", stdout);
#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
typedef double LD;
const int maxn = 110;
struct Node {
    LD r, c;
    bool operator < (const Node &o) const {
        return c < o.c;
    }
} a[maxn];
int dblcmp(LD x) {
    if (fabs(x) < esp) return 0;
    return x > 0 ? 1 : -1;
}
int n;

void check(LD x, LD &l, LD &r, LD V) {
    LD tV = V;
    l = r = 0;
    for (int i = 0; i < n && dblcmp(tV) > 0; i++) {

         LD v = min((double)tV, (double)(a[i].r*x));
        l += v*a[i].c;
        tV -= v;
    }

    tV = V;
    for (int i = n-1; i >= 0 && dblcmp(tV) > 0; i--) {
        LD v = min((double)tV, (double)(a[i].r*x));
        r += v*a[i].c;
        tV -= v;
    }
    l /= V, r /= V;
}
int main() {
    in
    out
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        LD V, X;
        cin >> n >> V >> X;
        LD sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &a[i].r, &a[i].c);
            sum += a[i].r;
        }
        sort(a, a+n);
        LD l = 0.0, r = 1e8 + 10;
        for (int i = 0; i < 200; i++) {
            if (fabs(l-r) < esp) break;
            LD mid = (l+r)/2.0;
            if (sum*mid < V) l = mid;
            LD tl, tr;
            check(mid, tl, tr, V);
            if (dblcmp(tr-X) < 0 || dblcmp(tl-X) > 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("Case #%d: ", t);
        if ((l+r)/2.0 >  1e8 + 1.0) {
            puts("IMPOSSIBLE");
        } else {
            printf("%.12f\n", (double)((l+r)/2.0));
        }
    }
    return 0;
}
