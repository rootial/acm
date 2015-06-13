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
int b[maxn], a[maxn];
int n, m;
bool check(LL mid) {
    int pos = n;
    memcpy(b, a, sizeof a);
    for (int i = 1; i <= m; i++) {
        LL tmp = mid - pos;
        if (tmp <= 0) return false;
        while (pos > 0 && tmp >= b[pos]) {
            tmp -= b[pos--];
        }
        if (pos > 0) b[pos] -= tmp;
        if (pos == 0) break;
    }
    return pos == 0;
}
int main() {
//    in
    cin >> n >> m;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        sum += a[i];
    }
    while(n > 0 && a[n] == 0) {
        n--;
    }
    LL l = n+1, r = sum + n;
    while (l < r) {
        LL mid = (l+r)/2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    printf("%I64d\n", l);
    return 0;
}
