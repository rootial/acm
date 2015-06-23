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


int main() {
//    in
    int w, m;
    cin >> w >> m;
    bool ok = true;
    bool carry = false;
    if (w == 2) {
        puts("YES");
        return 0;
    }
//    }
    while (m) {
        int dig = m%w;
        if (!carry) {
            if (dig == 0 || dig == 1) ;
            else if (dig == w-1) {
                carry = true;
            } else {
                ok = false;
                break;
            }
        } else {
            if (dig == 0) {
                carry = false;
            } else if (dig == w-1 || dig == w-2) {
            } else {
                ok = false;
                break;
            }
        }
        m /= w;
    }
    puts(ok ? "YES":"NO");
    return 0;
}
