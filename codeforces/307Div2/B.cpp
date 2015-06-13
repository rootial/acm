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
const int maxn = (int)1e5 + 10;
char a[maxn], b[maxn], c[maxn];
int cnta[26], cntb[26], cntc[26];
int id(char ch) {
    return ch - 'a';
}
void cal(char *s, int *cnt) {
    for (int i = 0; s[i]; i++) {
        cnt[id(s[i])]++;
    }
}
int main() {
//    in
    scanf("%s%s%s", a, b, c);
    cal(a, cnta);
    cal(b, cntb);
    cal(c, cntc);
    int lena = strlen(a);
    int lenb = strlen(b);
    int lenc = strlen(c);
    int x = 0, y = 0;
    int ok;
    for (int i = 0; i <= lena/lenb; i++) {
        int minh = inf;
        ok = 1;
        for (int k = 0; k < 26; k++) {

            if (cnta[k] >= cntb[k]*i) {
                if (cntc[k] > 0)
                    minh = min(minh, (cnta[k]-cntb[k]*i)/cntc[k]);
            } else {
                ok = 0;
                break;
            }
        }
        if (!ok) break;
        if (minh != inf) {
            if (x+y < minh+i) {
                x = i;
                y = minh;
            }
        }
    }
//     cout << x << ' ' << y << endl;
    for (int i = 0; i < x; i++)
        printf("%s", b);
    for (int i = 0; i < y; i++)
        printf("%s", c);
    for (int k = 0; k < 26; k++) {
        cnta[k] -= x*cntb[k] +y*cntc[k];
    }

    for (int k = 0; k < 26; k++)
        for (int j = 0; j < cnta[k]; j++)
            putchar((char)(k+'a'));
    puts("");
    return 0;
}
