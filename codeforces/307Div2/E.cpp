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
typedef pair<LL, LL> PII;
typedef MPS::iterator IT;
const int maxn = (int)5e5 + 10;
LL comSum[maxn];
PII r[maxn];
int L, n, q;

int main() {
//    in
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        LL tmp;
        scanf("%I64d", &tmp);
        r[i] = PII(tmp, i);
    }
//    L = 500;
    L = max((int)sqrt(n+.5), 1);
    for (int i = 0; i < n; i += L) {
        sort(r+i, r+min(n, i+L));
    }
    while (q--) {
        int type;
        int li, ri, x;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d%d", &li, &ri, &x);
            li--, ri--;
            int lowG = li/L;
            int upG = ri/L;
            for (int i = 0; i < L; i++) {
                int pos = lowG*L+i;
                if (pos > n) break;
                int id = r[pos].second;

                if (id <= ri && id >= li) {
                    r[pos].first += x;
                }
            }
            sort(r+lowG*L, r+min(lowG*L+L, n));

            if (lowG == upG) continue;
            for (int i = 0; i < L; i++) {
                int pos = upG*L+i;
                if (pos > n) break;
                int id = r[pos].second;
                if (id <= ri && id >= li) {
                    r[pos].first += x;
                }
            }
            sort(r+upG*L, r+min(upG*L+L, n));
            for (int k = lowG+1; k < upG; k++) {
                comSum[k] += x;
            }
        } else {
            scanf("%d", &x);
            int lvalue = inf, rvalue = -1;

            for (int i = 0; i < n; i += L) {
                int up = min(n, i+L);
                int k1 = lower_bound(r+i, r+up, PII(x-comSum[i/L], -1))-r;
                int k2 = lower_bound(r+i, r+up, PII(x-comSum[i/L]+1, -1))-r;

                if (k1 == up || r[k1].first+comSum[r[k1].second/L] != x) continue;
                lvalue = min(lvalue, (int)r[k1].second);
                rvalue = max(rvalue, (int)r[k2-1].second);
            }
            if (lvalue != inf) {
                printf("%d\n", rvalue-lvalue);
            } else {
                puts("-1");
            }
        }
    }

    return 0;
}
