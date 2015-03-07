
#line 3 "PairsOfStrings.cpp"

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

const int M = 1000000007;

class PairsOfStrings {
public:
    int num[1500];
    int powmod(LL a, LL b, LL c) {
        LL res = 1;
        while(b) {
            if(b&1) res = res*a%c;
            a = a*a%c;
            b >>= 1;
        }
        return res;
    }
    void addIt(int &x, int y) {
        x = (x+y)%M;
        if(x < 0) x += M;
    }
    void getDivisors(int n, vector<int> &div) {
        div.clear();
        int m = (int)sqrt(n+.5);
        for(int i = 1; i <= m; i++)
            if(n%i == 0) {
                div.pb(i);
                if(n/i != i)
                    div.pb(n/i);
            }
        sort(div.begin(), div.end());
    }
    vector<int> div;
    int getNumber(int n, int k) {

        getDivisors(n, div);
        int ans = 0;
        for(int i = 0; i < sz(div); i++) {
            int x = div[i];
            num[i] = powmod(k, x, M);
            for(int j = 0; j < i; j++) {
                int y = div[j];
                if(x%y == 0) {
                    addIt(num[i], -num[j]);
                }
            }
            addIt(ans, 1LL*num[i]*x%M);
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
        int Arg0 = 2;
        int Arg1 = 2;
        int Arg2 = 6;
        verify_case(0, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_1() {
        int Arg0 = 3;
        int Arg1 = 2;
        int Arg2 = 20;
        verify_case(1, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_2() {
        int Arg0 = 3;
        int Arg1 = 4;
        int Arg2 = 184;
        verify_case(2, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_3() {
        int Arg0 = 6;
        int Arg1 = 2;
        int Arg2 = 348;
        verify_case(3, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_4() {
        int Arg0 = 100;
        int Arg1 = 26;
        int Arg2 = 46519912;
        verify_case(4, Arg2, getNumber(Arg0, Arg1));
    }

// END CUT HERE

};


// BEGIN CUT HERE
int main() {
    PairsOfStrings ___test;
    ___test.run_test(-1);

}
// END CUT HERE
