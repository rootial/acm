
#line 3 "SplitIntoPairs.cpp"

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

class SplitIntoPairs {
public:
    int makepairs(vector <int> A, int X) {
//       int n = sz(A);
       sort(A.begin(), A.end());
       vector<int> B, C;
       for(int i = 0; i < sz(A); i++){
           if(A[i] >= 0) B.pb(A[i]);
           else C.pb(A[i]);
       }
       int n = sz(B), m = sz(C);
       if(n%2 == 0) return (n+m)/2;
       return (n+m)/2-(1LL*C[m-1]*B[0] < X);
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 0; verify_case(0, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 1; verify_case(1, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-5,-4,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 2; verify_case(2, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5,-7,8,-2,-5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -7; int Arg2 = 3; verify_case(3, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,4,5,6,6,-6,-4,-10,-1,-9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -2; int Arg2 = 4; verify_case(4, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1000000,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -5; int Arg2 = 1; verify_case(5, Arg2, makepairs(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SplitIntoPairs ___test;
    ___test.run_test(-1);
}
// END CUT HERE
