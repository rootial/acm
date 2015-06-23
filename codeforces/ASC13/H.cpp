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

#define IN freopen("sand.in", "r", stdin);
#define OUT freopen("sand.out", "w", stdout);

#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;

int main() {
//    in
IN
OUT
    int h, r, s, m;
    cin >> h >> r >> s >> m;
    double r0 = 1.0*s/h*r;

    double V = pi*pf(r0)*s/3.0;
    V /= m;
    double h0 = s;
    double l0 = sqrt(pf(s)+pf(r0));
    printf("%.12f\n", l0);

    for (int i = 0; i < m-1; i++) {
        double x = (1.0/3*pi*pf(r0)*h0-V);
        x /= (1.0/3*pi*pf(r0)*h0);
        x = pow(x, 1.0/3);
        x = (1.0-x)*l0;
        printf("%.12f\n", l0-x);
        double rt = (l0-x)/l0;
        l0 -= x;
        h0 *= rt;
        r0 *= rt;
    }
    return 0;
}
