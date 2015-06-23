#include<iostream>
#include<cstdio>
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
//typedef map<LL, int> MPS;
//typedef pair<int, int> PII;
//typedef MPS::iterator IT;

int main() {
//    in
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        LL n;
        cin >> n;
        if (n == 0) {
            puts("0");
            continue;
        }
        int ans = 0;
        bool here = false;
        int dig;
        while (n) {
            dig = n&1;
            if (dig == 1) {
                if (here == false) {
                    ans++;
                    here = true;
                }
            }  else {
                here = false;
            }
            n >>= 1;
        }
//        ans += dig;
        cout << ans << endl;
    }
    return 0;
}
