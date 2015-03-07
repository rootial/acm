
#line 3 "Decipherability.cpp"

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
char sa[maxn], sb[maxn];
string str;
int dp[maxn][maxn];

class Decipherability {
public:
    int len;
    int LCS(int n, int m, bool rev) {
        if(n == 0 || m == 0) return 0;
        if(rev) {
            for(int i = n-1; i >= 0; i--)
                sa[n-1-i] = str[i];
            for(int i = m-1; i >= 0; i--)
                sb[m-1-i] = str[i];
        } else {
            for(int i = 0; i < n; i++)
                sa[i] = str[len-n+i];
            for(int i = 0; i < m; i++)
                sb[i] = str[len-m+i];
        }
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(sa[i-1] == sb[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
        return dp[n][m];
    }
    string check(string s, int K) {
        str = s;
        len = sz(s);
        if(len == K) return "Certain";
        int ok = 1;
        for(int i = 0; i < len; i++)
            for(int j = i+1; j < len; j++)if(s[i] == s[j]) {
                    if(LCS(i, j, true)+LCS(len-i-1, len-j-1, false) >= len-K-1) {
                        ok = 0;
                        break;
                    }
                }
        return ok ? "Certain" : "Uncertain";
    }

// BEGIN CUT HERE
public:
    void run_test(int Case) {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
        if ((Case == -1) || (Case == 4)) test_case_4();
        if ((Case == -1) || (Case == 5)) test_case_5();
        if ((Case == -1) || (Case == 6)) test_case_6();
    }
private:
    template <typename T> string print_array(const vector<T> &V) {
        ostringstream os;
        os << "{ ";
        for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }";
        return os.str();
    }
    void verify_case(int Case, const string &Expected, const string &Received) {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0() {
        string Arg0 = "abcda";
        int Arg1 = 3;
        string Arg2 = "Certain";
        verify_case(0, Arg2, check(Arg0, Arg1));
    }
    void test_case_1() {
        string Arg0 = "aba";
        int Arg1 = 1;
        string Arg2 = "Certain";
        verify_case(1, Arg2, check(Arg0, Arg1));
    }
    void test_case_2() {
        string Arg0 = "aba";
        int Arg1 = 2;
        string Arg2 = "Uncertain";
        verify_case(2, Arg2, check(Arg0, Arg1));
    }
    void test_case_3() {
        string Arg0 = "abcdabcd";
        int Arg1 = 3;
        string Arg2 = "Certain";
        verify_case(3, Arg2, check(Arg0, Arg1));
    }
    void test_case_4() {
        string Arg0 = "koukyoukoukokukikou";
        int Arg1 = 2;
        string Arg2 = "Uncertain";
        verify_case(4, Arg2, check(Arg0, Arg1));
    }
    void test_case_5() {
        string Arg0 = "wolfsothe";
        int Arg1 = 8;
        string Arg2 = "Uncertain";
        verify_case(5, Arg2, check(Arg0, Arg1));
    }
    void test_case_6() {
        string Arg0 = "aa";
        int Arg1 = 2;
        string Arg2 = "Certain";
        verify_case(6, Arg2, check(Arg0, Arg1));
    }

// END CUT HERE

};


//BEGIN CUT HERE
int main() {
    Decipherability ___test;
    ___test.run_test(-1);

}
//END CUT HERE
