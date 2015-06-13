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
const int maxn = (int)1e5 + 10;
int a[maxn];
int main() {
//    in
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        int n;
        LL ans = 0;
        for (int i = scanf("%d", &n); i <= n; i++) {
            scanf("%d", a+i);
            if (a[i] > a[i-1])
                ans += a[i]-a[i-1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
