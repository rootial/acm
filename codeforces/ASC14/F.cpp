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

#define IN freopen("painting.in", "r", stdin);
#define OUT freopen("painting.out", "w", stdout);

#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
typedef long double LD;
LD h, r, nud;
#define sina (1.0/nud)
#define cosa  sqrt(1-pf(sina))
#define sinb  sqrt(1-pf(cosb))
#define cosb  (h/r)
#define H (h+r-2*r*(cosa*cosb-sina*sinb)*cosa)

int main() {
    IN
    OUT
//    in
    r = 1.0;
    cin >> h >> nud;
    if (r > h*nud) {
        puts("1.000000");
        return 0;
    }
    cout << fixed << setprecision(10);
    cout << H/(h+r);
    return 0;
}
