
#line 3 "SegmentDrawing.cpp"

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

int src = 889, sink = 890;
const int maxn = 900;

struct Edge {
    int u, v, c;
    Edge() {}
    Edge(int u, int v, int c):u(u), v(v), c(c) {}
};
struct MaxFlow {
    int n, m;
    vector<int> G[maxn];
    vector<Edge> edges;
    int Now[maxn], Dfn[maxn];

    void init(int n) {
        this->n = n;
        for(auto &x:G)
            x.clear();
        edges.clear();
    }
    void add(int u, int v, int c) {
        edges.pb(Edge(u, v, c));
        edges.pb(Edge(v, u, 0));
        m = sz(edges);
        G[u].pb(m-2);
        G[v].pb(m-1);
    }
    int ISAP(int s, int flow) {
        if(s == sink) return flow;
        int vary, now = 0, tab = n, v;
        for(int i = 0; i < sz(G[s]); i++){
            Edge &e = edges[G[s][i]];
            if(e.c > 0) {
                if(Dfn[s] == Dfn[v = e.v] + 1)
                    vary = ISAP(v, min(flow-now, e.c)), now += vary,
                            e.c -= vary, edges[G[s][i]^1].c += vary;
                if(Dfn[src] == n) return now;
                if(e.c > 0) tab = min(tab, Dfn[v]);
                 if(flow == now) break;
            }
        }
        if(now == 0) {
//                assert(Dfn[s] < 900);
            if(--Now[Dfn[s]] == 0)
                Dfn[src] = n;
            ++Now[Dfn[s] = tab+1];
        }
        return now;
    }
    int getAns() {
        memset(Now, 0, sizeof Now);
        memset(Dfn, 0, sizeof Dfn);
        Now[0] = n;
        int res = 0;
        while(Dfn[src] < n) res += ISAP(src, inf);
        return res;
    }
} solver;

class SegmentDrawing {
public:
    int crossproduct(int x, int y, int z, int w) {
        int cp = x*w-y*z;
        return cp > 0 ? 1 : (cp < 0 ? -1 : 0);
    }
    bool segmentInsert(int x0, int y0, int x1, int y1,
                       int x2, int y2, int x3, int y3) {
        int dx0 = x2-x0, dx1 = x3-x0, dx2 = x1-x0;
        int dy0 = y2-y0, dy1 = y3-y0, dy2 = y1-y0;
        if(crossproduct(dx2, dy2, dx0, dy0)*crossproduct(dx2, dy2, dx1, dy1) > 0) return false;
        dx0 = x0-x2, dx1 = x1-x2, dx2 = x3-x2;
        dy0 = y0-y2, dy1 = y1-y2, dy2 = y3-y2;
        if(crossproduct(dx2, dy2, dx0, dy0)*crossproduct(dx2, dy2, dx1, dy1) > 0) return false;
        return true;
    }
    int maxScore(vector <int> x, vector <int> y, vector <int> r, vector <int> b) {
        int n = sz(x);
        int m = n*n;
        int ans = accumulate(r.begin(), r.end(), 0)+accumulate(b.begin(), b.end(), 0);
        ans /= 2;
        solver.init(891);
        for(int i = 0; i < m; i++) {
            if(i/n >= i%n) continue;
            int x0 = i/n, y0 = i%n;
            solver.add(src, i, r[i]);
            solver.add(i+m, sink, b[i]);
            solver.add(i, i+m, inf);
//            bug(1)
            for(int j = 0; j < m; j++) {
                if(j/n >= j%n) continue;
                int x1 = j/n, y1 = j%n;
                if(i != j) {
                    if(segmentInsert(x[x0], y[x0], x[y0], y[y0], x[x1], y[x1], x[y1], y[y1]))
                        solver.add(i, j+m, inf);
                }
            }
        }
//		bug(ans)
        return ans - solver.getAns();
    }

// BEGIN CUT HERE
public:
    void run_test(int Case) {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
        if ((Case == -1) || (Case == 4)) test_case_4();
    }
private:
    template <typename T> string print_array(const vector<T> &V) {
        ostringstream os;
        os << "{ ";
        for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }";
        return os.str();
    }
    void verify_case(int Case, const int &Expected, const int &Received) {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0() {
        int Arr0[] = {0,1,0,-1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1,0,-1,0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0, 1, 2, 3,
                      1, 0, 6, 4,
                      2, 6, 0, 5,
                      3, 4, 5, 0
                     };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {0, 2, 3, 7,
                      2, 0, 4, 6,
                      3, 4, 0, 5,
                      7, 6, 5, 0
                     };
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 27;
        verify_case(0, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1() {
        int Arr0[] = {0, 1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1, 0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0, 101, 101, 0};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {0, 100, 100, 0};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 101;
        verify_case(1, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2() {
        int Arr0[] = {-3, -1, -1,  1,  1,  3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = { 0, -2,  2, -2,  2,  0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0, 2, 1, 2, 1, 2,
                      2, 0, 2, 1, 2, 1,
                      1, 2, 0, 2, 1, 2,
                      2, 1, 2, 0, 2, 1,
                      1, 2, 1, 2, 0, 2,
                      2, 1, 2, 1, 2, 0
                     };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0,
                      0, 0, 0, 21, 0, 0,
                      0, 0, 21, 0, 0, 0,
                      0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0
                     };
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 25;
        verify_case(2, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3() {
        int Arr0[] = {-100, 100, 0, -10, 10, 0};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0, 0, 100, 10, 10, 1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = { 0, 96, 96, 25, 25, 25,
                       96,  0, 96, 25, 25, 25,
                       96, 96,  0, 25, 25, 25,
                       25, 25, 25,  0, 10, 10,
                       25, 25, 25, 10,  0, 10,
                       25, 25, 25, 10, 10,  0
                     };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = { 0, 30, 30, 20, 20, 20,
                       30,  0, 30, 20, 20, 20,
                       30, 30,  0, 20, 20, 20,
                       20, 20, 20,  0, 86, 86,
                       20, 20, 20, 86,  0, 86,
                       20, 20, 20, 86, 86,  0
                     };
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 546;
        verify_case(3, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4() {
        int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0, 15, 2, 3, 4, 5, 6, 7, 8, 9,
                      15, 0, 15, 2, 3, 4, 5, 6, 7, 8,
                      2, 15, 0, 15, 2, 3, 4, 5, 6, 7,
                      3, 2, 15, 0, 15, 2, 3, 4, 5, 6,
                      4, 3, 2, 15, 0, 15, 2, 3, 4, 5,
                      5, 4, 3, 2, 15, 0, 15, 2, 3, 4,
                      6, 5, 4, 3, 2, 15, 0, 15, 2, 3,
                      7, 6, 5, 4, 3, 2, 15, 0, 15, 2,
                      8, 7, 6, 5, 4, 3, 2, 15, 0, 15,
                      9, 8, 7, 6, 5, 4, 3, 2, 15, 0
                     }
                     ;
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9,
                      0, 0, 0, 2, 3, 4, 5, 6, 7, 8,
                      2, 0, 0, 0, 2, 3, 4, 5, 6, 7,
                      3, 2, 0, 0, 0, 2, 3, 4, 5, 6,
                      4, 3, 2, 0, 0, 100, 2, 3, 4, 5,
                      5, 4, 3, 2, 100, 0, 0, 2, 3, 4,
                      6, 5, 4, 3, 2, 0, 0, 0, 2, 3,
                      7, 6, 5, 4, 3, 2, 0, 0, 0, 2,
                      8, 7, 6, 5, 4, 3, 2, 0, 0, 0,
                      9, 8, 7, 6, 5, 4, 3, 2, 0, 0
                     };
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 300;
        verify_case(4, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};


// BEGIN CUT HERE
//int main() {
//    SegmentDrawing ___test;
//    ___test.run_test(-1);
//
//}
// END CUT HERE
