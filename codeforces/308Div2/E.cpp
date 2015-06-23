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
const int maxn = 5555;
char s[maxn];
LL val[2][maxn];

LL calExe(int l, int r) {
    LL res = 0;
    int ll = l, rr = r;
    if (s[l-1] == '*') {

        LL tmp = 1;
        while (ll <= r && s[ll-1] == '*') {
            tmp *= s[ll] - '0';
            ll += 2;
        }
        res += tmp;
    }

    if (ll > rr) return res;
    if (rr >= ll && s[rr+1] == '*') {
        LL tmp = 1;

        while (rr >= ll && s[rr+1] == '*') {
            tmp *= s[rr] - '0';
            rr -= 2;
        }
        res += tmp;
    }
    if (ll <= rr) {
        res += val[0][rr] - val[0][ll-2];
    }
    return res;
}
void calMax(int lpos, int rpos, LL &ans) {
    LL res = 0;
    int l = lpos-2;
    LL tmp1 = 1;
    while (s[l+1] == '*') {
        tmp1 *= s[l] - '0';
        l -= 2;
    }
    res += val[0][l];
    int r = rpos+2;
    LL tmp2 = 1;
    while (s[r-1] == '*') {
        tmp2 *= s[r] - '0';
        r += 2;
    }
    res += val[1][r];

    ans = max(ans, res + tmp1 * tmp2 * calExe(lpos, rpos));
}
int main() {
//    in
    scanf("%s", s+2);
    s[0] = '0';
    s[1] = '+';
    int len = strlen(s);
    s[len++] = '+';
    s[len++] = '0';
    s[len] = '\0';
    vector<int> jpos, mpos;

    for (int i = 0; i < len; i++) {
        if (s[i] == '+') {
            jpos.push_back(i);
        } else if (s[i] == '*') {
            mpos.push_back(i);
        }
    }
    int j = 0;
    LL ans = 0;
    for (int i = 0; i < (int)jpos.size(); i++) {
        int ed = jpos[i];
        LL tmp = 1;
        while (j < ed) {
            tmp *= (s[j]-'0');
            j+=2;
        }
        ans = (val[0][ed-1] = (i == 0 ? 0 : val[0][jpos[i-1]-1]) + tmp);
    }
    val[1][0] = val[0][len-3] = ans;

    for (int i = 0; i < (int)jpos.size();  i++) {
        int pos = jpos[i];
        val[1][pos+1] = ans - val[0][pos-1];
    }
//    calMax(2, 4, ans);
//    cout << ans << endl;
    for (int i = 0; i < (int)mpos.size(); i++) {
        int pos = mpos[i];
        for (int j = pos+1; j < len-2; j += 2) {
            calMax(pos+1, j, ans);
        }
        for (int j = pos-1; j > 1; j -= 2) {
            calMax(j, pos-1, ans);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
