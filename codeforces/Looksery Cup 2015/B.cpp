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
int a[maxn][maxn], b[maxn];
int vis[maxn];

int main() {
//    in
    int n;
    cin >> n;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < n; j++) {
            a[i][j] = maze[i][j] == '1';
        }
    }
//    cout << maze[0] << endl;
    for (int i = 0; i < n; i++) {
        scanf("%d", b+i);
    }
    int cnt = n;
    while (cnt > 0) {
        int here = 0;
        for (int i = 0; i < n; i++) if (!vis[i] && !b[i]) {
            here = 1;
//            cout << i << endl;
            ans.push_back(i+1);
            vis[i] = 1;
            for (int j = 0; j < n; j++) {
                if (a[i][j]) b[j]--;
            }
            break;
        }
        if (!here) {
            break;
        }
    }
    cout << (int)ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%d%c", ans[i], i == (int)ans.size()-1 ? '\n' : ' ');
    }
    return 0;
}
