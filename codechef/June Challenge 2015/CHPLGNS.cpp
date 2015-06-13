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
#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
//Chef and Polygons
const int maxn = (int)1e5 + 10;

struct point {
    int x, y;
    point(){}
    point(int x, int y):x(x), y(y){}
    void input() {
        scanf("%d%d", &x, &y);
    }
};

double det(const point &a, const point &b) {
    return 1.0*a.x * b.y - 1.0*a.y * b.x;
}
int dblcmp(double x) {
    if (fabs(x) < esp) return 0;
    return x > 0 ? 1 : -1;
}
double area[maxn];
int r[maxn], ans[maxn];
point a[maxn];

bool cmp(int x, int y) {
    return dblcmp(area[x]-area[y]) < 0;
}
int main() {
//    in
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            r[i] = i;
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                a[j].input();
            }
            a[m] = a[0];
            area[i] = 0;
            for (int j = 0; j < m; j++) {
                area[i] += det(a[j], a[j+1]);
            }
            area[i] = fabs(area[i])/2.0;
        }
//        cout << area[0] << endl;
        sort(r, r+n, cmp);
//        cout << r[0] << endl;
        for (int i = 0;  i < n; i++) {
            ans[r[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
        }

    }
    return 0;
}
