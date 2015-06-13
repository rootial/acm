#line 2 "RookGraph.cpp"
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
class RookGraph {
public:
    int countPlacements(int N, vector <string> graph) {

    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; string Arr1[] = {"11",
 "11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 896; verify_case(0, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; string Arr1[] = {"111",
 "110",
 "101"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6272; verify_case(1, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arr1[] = {"11111",
 "11111",
 "11111",
 "11111",
 "11111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; string Arr1[] = {"1010000100",
 "0100101000",
 "1011010100",
 "0011010000",
 "0100100000",
 "0011010010",
 "0100001001",
 "1010000110",
 "0000010110",
 "0000001001"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 289151874; verify_case(3, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; string Arr1[] = {"10111110000",
 "01011010000",
 "10100010011",
 "11010110001",
 "11001100101",
 "10011100110",
 "11110011111",
 "00000011100",
 "00001111100",
 "00100110010",
 "00111010001"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 31; string Arr1[] = {"10000000000000000000000000000000000000000000000000",
 "01000000000000000000000000000000000010000000010000",
 "00100000000010000000000100001100000000010010000000",
 "00010000000010000000001000000000000000000000000000",
 "00001000000000000000000000000000000000100000000000",
 "00000100101000000010000000000000000000100100000001",
 "00000010000000000100000001000000000000000000000001",
 "00000001000000001000000000000000000000000000000100",
 "00000100101000000000000000000000000000000000000001",
 "00000000010000000000000010000010000000000000100000",
 "00000100101000000000000000000010000000000000000001",
 "00000000000100000010000100001000000001001000100000",
 "00110000000010000000001000001000000000000010000000",
 "00000000000001000000000000000000000000000000000000",
 "00000000000000100000000000000000001010000000000010",
 "00000000000000010000000000100000000000000000000000",
 "00000001000000001000000000000000000000010000000000",
 "00000010000000000100000001000000010000000000000000",
 "00000100000100000010000000001000000001101100000000",
 "00000000000000000001000000000001000000000000001100",
 "00000000000000000000110000000000100000000000000010",
 "00000000000000000000110010000000100000000010000000",
 "00010000000010000000001000000001000000000001000000",
 "00100000000100000000000100000100000000010000100000",
 "00000000010000000000010011000000000000000010000000",
 "00000010000000000100000011000000000000000000000000",
 "00000000000000010000000000100000001000001000000000",
 "00000000000000000000000000010000010100000000000000",
 "00100000000110000010000000001000000001001010000000",
 "00100000000000000000000100000100000000010000000000",
 "00000000011000000000000000000010000000000000100000",
 "00000000000000000001001000000001000000000001001100",
 "00000000000000000000110000000000100100000000000000",
 "00000000000000000100000000010000010000000000000000",
 "00000000000000100000000000100000001000001000000000",
 "00000000000000000000000000010000100100000000000000",
 "01000000000000100000000000000000000010000000010010",
 "00000000000100000010000000001000000001001000000000",
 "00001100000000000010000000000000000000100100000000",
 "00100000000000001000000100000100000000010000000000",
 "00000000000100000010000000101000001001001000000000",
 "00000100000000000010000000000000000000100100000000",
 "00100000000010000000010010001000000000000010000000",
 "00000000000000000000001000000001000000000001000000",
 "00000000010100000000000100000010000000000000100000",
 "01000000000000000000000000000000000010000000010000",
 "00000000000000000001000000000001000000000000001100",
 "00000001000000000001000000000001000000000000001100",
 "00000000000000100000100000000000000010000000000010",
 "00000110101000000000000000000000000000000000000001"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(5, Arg2, countPlacements(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RookGraph ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
