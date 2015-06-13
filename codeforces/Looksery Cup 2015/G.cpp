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

const int maxn = (int)2e5 + 10;
int a[maxn];
int main() {
//    in
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        a[i] += i;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    if (a[i] == a[i-1]) {
        puts(":(");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    printf("%d%c", a[i]-i, i == n ? '\n' : ' ');
    return 0;
}
