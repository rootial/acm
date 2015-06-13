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
#define TTL(x) assert((double)clock() / CLOCKS_PER_SEC * 1000 < (x));
#define inf 0x0f0f0f0f

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef map<ULL, int> MPS;
typedef pair<int, int> PII;
typedef MPS::iterator IT;
//http://www.codechef.com/JUNE15/problems/CHSTR
const int maxn = 5000 + 4;
const int MOD = (int)1e9 + 7;
const int Seed = (int)1e6 + 7;

int nCr[maxn][maxn];

void pre() {
    nCr[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1])%MOD;
        }
    }
}
MPS mps;
int cnt[maxn], ans[maxn];

char str[maxn];

int s[maxn], sa[maxn], t[maxn], t2[maxn], rk[maxn], h[maxn], c[maxn];
int n;

void buildSa(int m) {
    int *x = t, *y = t2;
    for(int i = 0; i < m; i++) c[i] = 0;
    for(int i = 0; i < n; i++) c[x[i]=s[i]]++;

    for(int i = 1; i < m; i++) c[i] += c[i-1];
    for(int i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
//    bug(n)
    for(int k = 1; k <= n; k <<= 1) {
//        bug(k)
        int p = 0;
        for(int i = n-k; i < n; i++) y[p++] = i;
        for(int i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i]-k;

        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[y[i]]]++;//
        for(int i = 1; i < m; i++) c[i] += c[i-1];
        for(int i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

        p = 1;
        swap(x, y);
        x[sa[0]] = 0;

        for(int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k] ? p-1 : p++;
//        bug(k)
        if(p >= n)
            break;
        m = p;
    }
}
void getHeight() {
    int k = 0, j;
    h[0] = 0;
    for(int i = 0; i < n; i++) rk[sa[i]] = i;
    for(int i = 0; i < n; i++) {
        if(k) k--;
        if(rk[i] == 0)
            continue;
        j = sa[rk[i]-1];
        while(s[i+k] == s[j+k])
            k++;
        h[rk[i]] = k;
    }
}
bool vis[maxn];
int l[maxn], r[maxn], pa[maxn], hi[maxn];
vector<int> hei[maxn];
int findpa(int x) {return x == pa[x] ? x : pa[x] = findpa(pa[x]);}
int go[maxn];
void Union(int x, int y) {
    int px = findpa(x);
    int py = findpa(y);
    pa[px] = py;
    l[py] = min(l[py], l[px]);
    r[py] = max(r[py], r[px]);
    hi[py] = min(hi[py], hi[px]);
}
int main() {
//    in
    pre();
    int T;
    for (int tt = scanf("%d", &T); tt <= T; tt++) {
        int q;
        scanf("%d%d", &n, &q);
        scanf("%s", str);

        memset(cnt, 0, sizeof cnt);
        memset(ans, 0, sizeof ans);
        memset(vis, 0, sizeof vis);
        memset(go, 0, sizeof go);
        for (int i = 0; i < maxn; i++)
            hei[i].clear();

        mps.clear();
        int len = strlen(str);
        if (len <= 500) {
            for (int i = 0; i < len; i++) {
                ULL hashVal = 0;
                for (int j = i; j < len; j++) {
                    hashVal = (hashVal * Seed + (int)(str[j] - 'a' + 1));
                    mps[hashVal]++;
                }
            }
            for (auto it:mps) {
                cnt[it.second]++;
            }
        } else {
            for (int i = 0; i < len; i++) {
                s[i] = str[i] - 'a' + 1;
            }

            s[n = len] = 0;
            n++;

            buildSa(27);
            getHeight();

            for (int i = 1; i < n; i++) {
                l[i] = i;
                r[i] = i;
                pa[i] = i;
                hei[h[i]].push_back(i);
                hi[i] = h[i];
            }
            for (int i = n; i >= 1; i--) {
                for (int j = 0; j < (int)hei[i].size(); j++) {

                    int u = hei[i][j];
//                    bug(u)
                    go[u] = 1;
                    if (u > 0 && go[u-1]) {
                        Union(u, u-1);
                    }
                    if (u < n-1 && go[u+1]) {
                        Union(u, u+1);
                    }
//                    cout << l[u] << r[u] << endl;
                }
//                bug(hi[3])
                for (int j = 0; j < (int)hei[i].size(); j++) {
                    int u = hei[i][j];
                    int pu = findpa(u);
//                    bug(pu)
                    int minh = hi[pu];
//                    cout << minh << endl;
                    int lowh = max(h[l[pu]-1], r[pu]+1 < n ? h[r[pu]+1] : 0);
//                    cout << r[pu] - l[pu] + 2 << ' ' << minh << endl;4
//                    system("pause");
//                    cout << h[l[pu]-1] << endl;
//                    if (r[pu]-l[pu]+2 == 2) {
//                        cout << minh-lowh << endl;
//                    }
                    cnt[r[pu]-l[pu]+2] += minh-lowh;
                }
            }
//            for (int i = 0; i < 6; i++)
//            cout << cnt[i] << endl;
//            for (int i = 1; i < n; i++) {
//                int j = 2;
//                while (1) {
//                    while (h[j] < i && j < n) {
//                        j++;
//                    }
//                    if (j >= n) break;
//                    int k = j;
//                    while (k < n && h[k] >= i) {
//                        k++;
//                    }
//                    cnt[k-j+1]++;
//                    j = k;
//                    if (j >= n) break;
//                }
//            }9

        }
//        for (int i = 0; i < n; i++)
//            cout << h[i] << endl;
        vector<int> used,fuck;
        for (int i = 1; i <= len; i++)
            if (cnt[i]) used.push_back(i);

//        assert((double)clock() / CLOCKS_PER_SEC * 1000 < 990);
        vector<int> que;

        for (int i = 0; i < q; i++) {
            int x;
            scanf("%d", &x);
            fuck.push_back(x);

            if (x <= len && !vis[x]) que.push_back(x);
            if (x <= len)
                vis[x] = 1;
        }
        sort(used.begin(), used.end());
        for (int i = 0; i < (int)que.size(); i++) {

            for (int j = lower_bound(used.begin(), used.end(), que[i]) - used.begin(); j < (int)used.size(); j++)
                ans[que[i]] = (ans[que[i]] + 1LL*cnt[used[j]]*nCr[used[j]][que[i]]%MOD)%MOD;
        }
        for (int i = 0; i < q; i ++) {
            int x = fuck[i];
            if (x > len) {
                puts("0");
            } else {
                printf("%d\n", x == 1 ? (len+1)*len/2 : ans[x]);
            }
        }
    }
    return 0;
}
