#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-18
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("solve_in.txt", "r", stdin);
#define out freopen("solve_out.txt", "w", stdout);
#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int maxn = 155;
char maze[maxn][maxn];
int dblcmp(long double x) {
    if (fabs(x) < esp) return 0;
    return x > 0 ? 1 : -1;
}
void  check(long double l0, long double r0, long double l1, long double r1, long double &L, long double &R) {
    L = min(min(l0*l1, l0*r1), min(r0*l1, r0*r1));
    R = max(max(l0*l1, l0*r1), max(r0*l1, r0*r1));
}
int main() {
//    in
    long double a, b, c, d, a0, a1, b0, b1, c0, c1, d0, d1;
    cin >> a >> b >> c >> d;
    double l = 0, r = 1e10;
    for (int i = 0; i < 500; i++) {
        long double mid = (l+r)/2.0;
        if (fabs(r-l) < 1e-18) break;
        a0 = a-mid, a1 = a+mid;
        b0 = b-mid, b1 = b+mid;
        c0 = c-mid, c1 = c+mid;
        d0 = d-mid, d1 = d+mid;
        long double L0, R0, L1, R1;
        check(a0, a1, d0, d1, L0, R0);
        check(c0, c1, b0, b1, L1, R1);

        if (dblcmp(R1 - L0) < 0  || dblcmp(L1 - R0) > 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.12f\n", (double)(l+r)/2.0);
    return 0;
}
