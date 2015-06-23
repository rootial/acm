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
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int Base = 210;
const int maxn = 2000 + 10;

int cnt[Base][Base*2];
int x[maxn], y[maxn];
LL ans;
int n;
int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a%b);
}
void solve(int p) {
    memset(cnt, 0, sizeof cnt);
    for (int i = p+1; i < n; i++) {

        int dx = x[i]-x[p];
        int dy = y[i]-y[p];
        if (dx < 0) {
            dx *= -1;
            dy *= -1;
        }
        if (dx == 0 && dy < 0) {
            dy *= -1;
        }
        int gcd = GCD(dx, abs(dy));
        dx /= gcd;
        dy /= gcd;
        ans -= cnt[dx][dy];
        cnt[dx][dy]++;
    }
}
int main() {
//    in
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", x+i, y+i);
    }
    ans = 1ll*n*(n-1)*(n-2)/6;
    for (int i = 0; i < n; i++) {
        solve(i);
    }
    printf("%I64d\n", ans);
    return 0;
}
