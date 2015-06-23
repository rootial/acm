#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>

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
const int maxn = 1111;
int dp[maxn][maxn], sum[maxn][maxn];
int a[maxn];

int main () {
//    in
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j-1] + (j < i && a[j] > a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + dp[i][j];
        }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r][r]-sum[l-1][r]-(sum[r][l-1]-sum[l-1][l-1]));
    }
    return 0;
}
