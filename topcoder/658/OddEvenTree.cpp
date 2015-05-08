#line 2 "OddEvenTree.cpp"
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
const int maxn = 55;
int dep[maxn];
int pa[maxn][10];
bool used[maxn];

using namespace std;
class OddEvenTree {
public:
    int getLca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int d = dep[u]-dep[v];
        for (int i = 0; i < 10; i++) if ((1<<i)&d) {
                u = pa[u][i];
            }
        if (u != v) {
            for (int i = 9; i >= 0; i--) if (pa[u][i] != pa[v][i]) {
                    u = pa[u][i];
                    v = pa[v][i];
                }
            u = pa[u][0];
        }
        return u;
    }
    vector <int> getTree(vector <string> x) {


        int n = (int)x.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (x[i][j] != x[j][i] || (i == j && x[i][j] == 'O')) return  vector<int> (1, -1);
        for (int st = 0; st < n; st++) {
            memset(dep, 0, sizeof dep);
            memset(used, false, sizeof used);
            for (int i = 0; i < maxn; i++)
                for (int j = 0; j < 10; j++)
                pa[i][j] = st;

            vector<int> ans;
            int cnt = 0;
            queue<int> q;
            q.push(st);
            used[st] = true;
            while (q.size()) {
                int u = q.front();
                q.pop();

                for (int i = 0; i < n; i++) {
                    if (!used[i]) {
                        pa[i][0] = u;
                        dep[i] = dep[u] + 1;
                        int ok = 1;
                        for (int j = 0; j < n; j++) if (i != j) {
                                if (used[j]) {
                                    int lca = getLca(i, j);
                                    int dist = dep[i] + dep[j] - 2*dep[lca];
                                    if ((dist%2 == 0 && x[i][j] == 'O') ||
                                            (dist%2 && x[i][j] == 'E')) {
                                        ok = 0;
                                        break;
                                    }
                                }
                            }
                        if (ok) {
                            for (int j = 1; j < 10; j++) {
                                pa[i][j] = pa[pa[i][j-1]][j-1];
                            }
                            used[i] = true;
                            q.push(i);
                            cnt++;
                            ans.push_back(i);
                            ans.push_back(u);
                        }
                    }
                }
            }
            if ((int)ans.size() == 2*n-2)  return ans;
        }
//        bug(n)
//        bug((int)ans.size())
//        bug((int)ans.size() != 2*n-2)
        return vector<int> (1, -1);;
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
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: " << print_array(Expected) << endl;
            cerr << "\tReceived: " << print_array(Received) << endl;
        }
    }
    void test_case_0() {
        string Arr0[] = {"EOOOE",
                         "OEEOO",
                         "OEEEO",
                         "OOEEE",
                         "EOOEE"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0, 1, 2, 1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, getTree(Arg0));
    }
    void test_case_1() {
        string Arr0[] = {"EO",
                         "OE"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0, 1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, getTree(Arg0));
    }
    void test_case_2() {
        string Arr0[] = {"OO",
                         "OE"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {-1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, getTree(Arg0));
    }
    void test_case_3() {
        string Arr0[] = {"EO",
                         "EE"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {-1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, getTree(Arg0));
    }
    void test_case_4() {
        string Arr0[] = {"EOEO",
                         "OEOE",
                         "EOEO",
                         "OEOE"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0, 1, 0, 3, 2, 1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(4, Arg1, getTree(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    OddEvenTree ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
