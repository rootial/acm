#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-8
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("solve_in.txt", "r", stdin);
#define out freopen("solve_out.txt", "w", stdout);
#define bug(x) cerr << "Line : " << (x) <<  " >>>>>>\n";
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<LL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
const int maxn = 55;
char maze[maxn][maxn];

int main() {
//    in
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", maze[i]);
//        cout << maze[0] << endl;
    int ans = 0;
    for (int i = 0; i <= n-2; i++) {
        for (int j = 0; j <= m-2; j++) {
            string s = "";
            s += maze[i][j];
            s += maze[i+1][j];
            s += maze[i+1][j+1];
            s += maze[i][j+1];

            sort(s.begin(), s.end());
//            cout << s << endl;
            if (s == "acef") ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
