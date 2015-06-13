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
long long n, k;
int l, m;
struct Ma {
    ULL a[2][2];
    Ma() {
        memset(a, 0, sizeof a);
    }
    Ma(ULL x, ULL y, ULL z, ULL w) {
        a[0][0] = x, a[0][1] = y;
        a[1][0] = z, a[1][1] = w;
    }
    Ma operator * (const Ma &o) {
        Ma res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k]*o.a[j][k]%m)%m;
                }
        return res;
    }
};
int main() {
//    in
//    cout << (double)(1ULL<<63) << endl;
    scanf("%I64d%I64d%d%d", &n, &k, &l, &m);
    Ma tmp(1, 1, 1, 0);
    Ma ma(1, 0, 0, 1);
    ULL N = n;
    LL ret = 1, c = 2;
    LL tt = n;
    while (tt) {
        if (tt&1) {
            ret = ret*c%m;
        }
        c = c*c%m;
        tt >>= 1;
    }
    N--;
    while (N) {
        if (N&1) {
            ma = ma*tmp;
        }
        N >>= 1;
        tmp = tmp*tmp;
    }

    ULL res1 = (ma.a[0][0] + ma.a[0][1])%m;
    ULL res2 =  (ma.a[1][0] + ma.a[1][1])%m;

    res1 = (res1 + res2) % m;
    ret = (ret-(LL)res1)%m;
    if (ret < 0) ret += m;
    res2 = ret;
//    cout << res1 << ' ' << res2 << endl;
    ULL res = 1;
    if (l < 63 && (k  >= (1ll<<l))) {
        puts("0");
    } else {
        for (int i = 0; i < l; i++) {
            if ((1ULL<<i)&(ULL)k) {
                res = res * res2 % m;
            } else {
                res = res * res1 % m;
            }
        }
        printf("%I64u\n", res%m);
    }

    return 0;
}
