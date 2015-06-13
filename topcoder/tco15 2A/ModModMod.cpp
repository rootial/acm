#line 2 "ModModMod.cpp"
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
typedef map<LL, int> MPS;
typedef MPS::iterator IT;

using namespace std;
const int maxn = 5000 + 5;
LL ret[maxn];
int mod[maxn];
int cnt;

class ModModMod {
public:
    LL dfs(int R, int dep) {
        if (R == 0) return 0;
//        bug(R)
        if (R == mod[dep]-1 && ret[dep] >= 0) return ret[dep];
        if (dep == cnt-1) {
            return 1LL*R/(mod[dep])*(1LL*(mod[dep]-1)*mod[dep]/2) + (1LL*(R%mod[dep])*((R%mod[dep])+1)/2);
        }
        LL res = 1LL*R/mod[dep]*dfs(mod[dep]-1, dep+1) + dfs(R%mod[dep], dep+1);
        if (R == mod[dep]-1) ret[dep] = res;
        return res;
    }

    long long findSum(vector <int> m, int R) {
        int n = (int)m.size();
        cnt = 0;
        memset(ret, -1, sizeof ret);
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && m[j] >= m[i]) j++;
            mod[cnt++] = m[i];
        }
//        cout << cnt << endl;
        return dfs(R, 0);
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
    void verify_case(int Case, const long long &Expected, const long long &Received) {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0() {
        int Arr0[] = {5,3,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 10;
        long long Arg2 = 4LL;
        verify_case(0, Arg2, findSum(Arg0, Arg1));
    }
    void test_case_1() {
        int Arr0[] = {33, 15, 7, 10, 100, 9, 5};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 64;
        long long Arg2 = 92LL;
        verify_case(1, Arg2, findSum(Arg0, Arg1));
    }
    void test_case_2() {
        int Arr0[] = {995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 992363;
        long long Arg2 = 12792005LL;
        verify_case(2, Arg2, findSum(Arg0, Arg1));
    }
    void test_case_3() {
        int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
                     };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 100;
        long long Arg2 = 4950LL;
        verify_case(3, Arg2, findSum(Arg0, Arg1));
    }
    void test_case_4() {
        int Arr0[] = {2934};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 10000000;
        long long Arg2 = 14664070144LL;
        verify_case(4, Arg2, findSum(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ModModMod ___test;

    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
