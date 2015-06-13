#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-18
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
const int maxn = 110;
char maze[maxn][maxn];

int a[maxn][maxn], b[maxn][maxn];

int main() {
//    in
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; j++)
            a[i][j] = maze[i][j] == 'W';
    }
    int x = n-1, y = m-1;
    int ans = 0;
    while (x >= 0 && y >= 0) {
        for (int i = x; i >= 0; i--) {
            if (maze[i][y] == 'W') {
                if (b[i][y] != 1) {
                    ans++;
                    int val = 1-b[i][y];
                    for (int r = 0; r <= i; r++)
                        for (int c = 0; c <= y; c++) {
                            b[r][c] += val;
                        }
                }
            } else {
                if (b[i][y] != -1) {
                    ans++;
                    int val = -1-b[i][y];
                    for (int r = 0; r <= i; r++)
                        for (int c = 0; c <= y; c++) {
                            b[r][c] += val;
                        }
                }
            }

        }
        for (int i = y; i >= 0; i--) {
            if (maze[x][i] == 'W') {
                if (b[x][i] != 1) {
                    ans++;
                    int val = 1-b[x][i];
                    for (int r = 0; r <= x; r++)
                        for (int c = 0; c <= i; c++) {
                            b[r][c] += val;
                        }
                }
            } else {
                if (b[x][i] != -1) {
                    ans++;
                    int val = -1-b[x][i];
                    for (int r = 0; r <= x; r++)
                        for (int c = 0; c <= i; c++) {
                            b[r][c] += val;
                        }
                }
            }
        }
        x--, y--;
    }
    cout << ans << endl;
    return 0;
}
