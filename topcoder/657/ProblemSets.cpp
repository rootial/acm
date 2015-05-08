#line 2 "ProblemSets.cpp"
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

using namespace std;
class ProblemSets {
public:
    long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {

        LL l = 0, r = (LL)9e18;

        while (l <= r) {
            LL e = E, em = EM, m = M, mh = MH, h = H;
            LL mid = (l+r)/2;
            if (E < mid) {
                em -= mid-E;
            }
            if (em < 0) {
                r = mid-1;
                continue;
            }
            if (H < mid) {
                mh -= mid-H;
                if (mh < 0) {
                    r = mid-1;
                    continue;
                }
            }
            if (em+mh+m < mid) {
                r = mid-1;
            } else l = mid+1;
        }
        return l-1;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 2LL; long long Arg5 = 3LL; verify_case(0, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 100LL; long long Arg1 = 100LL; long long Arg2 = 100LL; long long Arg3 = 0LL; long long Arg4 = 0LL; long long Arg5 = 0LL; verify_case(1, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 657LL; long long Arg1 = 657LL; long long Arg2 = 657LL; long long Arg3 = 657LL; long long Arg4 = 657LL; long long Arg5 = 1095LL; verify_case(2, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; long long Arg3 = 4LL; long long Arg4 = 5LL; long long Arg5 = 3LL; verify_case(3, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 1000000000000000000LL; long long Arg2 = 1000000000000000000LL; long long Arg3 = 1000000000000000000LL; long long Arg4 = 1000000000000000000LL; long long Arg5 = 1666666666666666666LL; verify_case(4, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ProblemSets ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
