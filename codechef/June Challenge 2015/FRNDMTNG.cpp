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
//Chef and His Friend

int main() {
    in
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        double T1, T2, t1, t2;
        scanf("%lf%lf%lf%lf", &T1, &T2, &t1, &t2);
        double ans = 0.0;
        if (t1 < T2) {
            ans += (T2-t1)*(T2-t1)/2.0;
            if (T2-t1 > T1) {
                ans -= (T2-t1-T1)*(T2-t1-T1)/2.0;
            }
        }

        if (t2 < T1) {
            ans += (T1-t2)*(T1-t2)/2.0;
            if (T1-t2 > T2) {
                ans -= (T1-t2-T2)*(T1-t2-T2)/2.0;
            }
        }
//        cout << ans << ' ' << T1*T2 << endl;
        ans /= (T1*T2);
        printf("%.12f\n", (double)(1.0-ans));
    }
    return 0;
}
