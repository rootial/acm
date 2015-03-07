
#line 3 "MiddleCode.cpp"

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
int vis[maxn];
class MiddleCode {
public:
    void Remove(string &s, int pos) {
        int len = s.size();
        string t = "";
        if(pos < 0 || pos >= len) return;
        for(int i = 0; i < len; i++)
            if(i != pos) t += s[i];
        s = t;
    }
    string encode(string s) {
        int n = s.size(), m = n;
        string ans = "";
        for(int i = 0; i < n; i++) {
            if((n-i)&1) {
                ans += s[(n-i)/2];
                Remove(s, (n-i)/2);
            } else {
                if(s[(n-i)/2] < s[(n-i)/2-1]) {
                    ans += s[(n-i)/2];
                    Remove(s, (n-i)/2);
                } else {
                    ans += s[(n-i)/2-1];
                    Remove(s, (n-i)/2-1);
                }
            }
        }
        return ans;
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
        string Arg0 = "word";
        string Arg1 = "ordw";
        verify_case(0, Arg1, encode(Arg0));
    }
    void test_case_1() {
        string Arg0 = "aaaaa";
        string Arg1 = "aaaaa";
        verify_case(1, Arg1, encode(Arg0));
    }
    void test_case_2() {
        string Arg0 = "abacaba";
        string Arg1 = "caabbaa";
        verify_case(2, Arg1, encode(Arg0));
    }
    void test_case_3() {
        string Arg0 = "shjegr";
        string Arg1 = "ejghrs";
        verify_case(3, Arg1, encode(Arg0));
    }
    void test_case_4() {
        string Arg0 = "adafaaaadafawafwfasdaa";
        string Arg1 = "afawadafawafaafsadadaa";
        verify_case(4, Arg1, encode(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MiddleCode ___test;
    ___test.run_test(-1);
}
//END CUT HERE
