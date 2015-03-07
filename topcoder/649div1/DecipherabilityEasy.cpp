
#line 3 "DecipherabilityEasy.cpp"

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

class DecipherabilityEasy {
	public:
	string check(string s, string t) {
		int n = s.size();
		int m = t.size();
		if(n-1 != m) return "Impossible";
		for(int i = 0; i < n; i++){
                string tmp = "";
            for(int j = 0; j < i; j++)
            tmp += s[j];
            for(int j = i+1; j < n; j++)
                tmp += s[j];
            if(tmp == t) return "Possible";
		}
		return "Impossible";
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "sunuke"; string Arg1 = "snuke"; string Arg2 = "Possible"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "snuke"; string Arg1 = "skue"; string Arg2 = "Impossible"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "snuke"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "snukent"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaa"; string Arg1 = "aaaa"; string Arg2 = "Possible"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaaa"; string Arg1 = "aaa"; string Arg2 = "Impossible"; verify_case(5, Arg2, check(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "topcoder"; string Arg1 = "tpcoder"; string Arg2 = "Possible"; verify_case(6, Arg2, check(Arg0, Arg1)); }
	void test_case_7() { string Arg0 = "singleroundmatch"; string Arg1 = "singeroundmatc"; string Arg2 = "Impossible"; verify_case(7, Arg2, check(Arg0, Arg1)); }

// END CUT HERE

};


//BEGIN CUT HERE
//int main()
//{
//DecipherabilityEasy ___test;
//___test.run_test(-1);
//
//}
//END CUT HERE
