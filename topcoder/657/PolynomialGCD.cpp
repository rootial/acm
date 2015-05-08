#line 2 "PolynomialGCD.cpp"
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
const int MOD = 1000000007;
using namespace std;
class PolynomialGCD {
public:
    int gcd(string s) {

    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "111"; int Arg1 = 6; verify_case(0, Arg1, gcd(Arg0)); }
	void test_case_1() { string Arg0 = "00000"; int Arg1 = 1; verify_case(1, Arg1, gcd(Arg0)); }
	void test_case_2() { string Arg0 = "2014"; int Arg1 = 16; verify_case(2, Arg1, gcd(Arg0)); }
	void test_case_3() { string Arg0 = "31415926535"; int Arg1 = 659897170; verify_case(3, Arg1, gcd(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PolynomialGCD ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
