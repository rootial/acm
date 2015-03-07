#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-14
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("solve_in.txt", "r", stdin);
#define bug(x) printf("Line : %u >>>>>>\n", (x));
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f
using namespace std;
typedef long long LL;
typedef unsigned US;
typedef pair<int, int> PII;
typedef map<PII, int> MPS;
typedef MPS::iterator IT;

const int maxn = 800 + 10;
//2-sat
struct twoSat {
    int n;
    int mark[maxn], S[maxn];
    vector<list<int> > g;
    int c;
    void init(int n) {
        this->n = n;
        g.resize(n*2);
        for(auto &x:g)
            x.clear();
        memset(mark, 0, sizeof mark);
    }
    void add(int x, int y) {
        g[x].pb(y);
    }
    bool dfs(int x) {
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        S[c++] = x;
        mark[x] = 1;
        for(int y: g[x]) {
            if(!dfs(y)) return false;
        }
        return true;
    }
    bool solve() {
        for(int i = 0; i < n*2; i += 2) {
            if(!mark[i] && !mark[i+1]) {
                c = 0;
                if(!dfs(i)) {
                    while(c) mark[S[--c]] = 0;
                    if(!dfs(i+1)) return false;
                }
            }
        }
        return true;
    }
} solver;
struct State {
    int a, b, c, d;
    State() {}
    State(int a, int b, int c, int d):a(a), b(b), c(c), d(d) {}
};
vector<State> sta;

class GCDLCM {
public:
    set<int> div;//relevant primes
    vector<PII> factor[200 + 10];
    //get prime factor of n, store in vec
    void getPrimeFac(int n) {
        for(int i = 2; i <= n/i; i++) {

            if(n%i == 0) {
                while(n%i == 0) {
                    n /= i;
                }
                div.insert(i);
            }
        }
        if(n != 1) {
            div.insert(n);
        }
    }
    bool contradiction(int x, int y) {
        int a0 = sta[x].a, b0 = sta[x].b, c0 = sta[x].c, d0 = sta[x].d;
        int a1 = sta[y].a, b1 = sta[y].b, c1 = sta[y].c, d1 = sta[y].d;
        if(a0 == a1 && c0 != c1) {
            return true;
        }
        if(a0 == b1 && ((d1 && c0 < c1) || (!d1 && c0 > c1))) {
            return true;
        }
        if(b0 == a1 && ((d0 && c1 < c0) || (!d0 && c1 > c0))) {
            return true;
        }
        if(b0 == b1 && ((d0 > d1 && c0 > c1) || (d0 < d1 && c0 < c1))) {
            return true;
        }
        return false;
    }
    string possible(int n, string type, vector <int> A, vector <int> B, vector <int> C) {
        int m = sz(A);
        for(int i = 0; i < m; i++)
            getPrimeFac(C[i]);
        for(int u: div) {
            sta.clear();
            for(int j = 0; j < m; j++) {
                int r = 0;
                int y = C[j];
                while(y%u == 0) {
                    r++;
                    y /= u;
                }
                sta.pb(State(A[j], B[j], r, type[j] == 'G'));
                sta.pb(State(B[j], A[j], r, type[j] == 'G'));
            }

            solver.init(sz(sta));
            //add edge x->~y, ~y->x,etc.
            for(int i = 0; i < sz(sta); i += 2) {
                //solver.add(i<<1, (i+1)<<1|1);
                solver.add((i+1)<<1|1, i<<1);
                //solver.add((i+1)<<1, i<<1|1);
                solver.add(i<<1|1, (i+1)<<1);
            }
            for(int i = 0; i < sz(sta); i++) for(int j = 0; j < sz(sta); j++) {
                    if(contradiction(i, j)) {
                        solver.add(i<<1, j<<1|1);
                        solver.add(j<<1, i<<1|1);
                    }
                }
            if(!solver.solve()) return  "Solution does not exist";
        }
        return  "Solution exists";
    }
};



