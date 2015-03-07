
#line 3 "CartInSupermarketEasy.cpp"

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
int dp[110][110];
class CartInSupermarketEasy {
public:

    int calc(int N, int K) {
        memset(dp, -1, sizeof dp);
        for(int i = 0; i <= N; i++)
            dp[i][0] = i;
        for(int i = 0; i <= K; i++)
            dp[0][i] = 0;
//            cout << dp[0][0] << endl;
//            cout << (~0) << endl;
        return dfs(N, K);
    }
    int dfs(int x, int y) {
//        if(x == 0) return 0;
//        if(y == 0) return x;
        int &res = dp[x][y];
//        cout << dp[x][y] << endl;
        //        cout << res << endl;
//        cout << x << y << endl;
//        cout << res << endl;
        if(~res) return res;
        res = x;
        res = min(res, dfs(x-1, y) + 1);
        y--;
        for(int i = 1; i < x; i++)
            for(int j = 0; j <= y; j++) {
                res = min(res, max(dfs(i,j), dfs(x-i, y-j))+1);
            }
//        if(res == 0) cout << x << y << endl;
        return res;
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
        int Arg0 = 5;
        int Arg1 = 0;
        int Arg2 = 5;
        verify_case(0, Arg2, calc(Arg0, Arg1));
    }
    void test_case_1() {
        int Arg0 = 5;
        int Arg1 = 2;
        int Arg2 = 4;
        verify_case(1, Arg2, calc(Arg0, Arg1));
    }
    void test_case_2() {
        int Arg0 = 15;
        int Arg1 = 4;
        int Arg2 = 6;
        verify_case(2, Arg2, calc(Arg0, Arg1));
    }
    void test_case_3() {
        int Arg0 = 7;
        int Arg1 = 100;
        int Arg2 = 4;
        verify_case(3, Arg2, calc(Arg0, Arg1));
    }
    void test_case_4() {
        int Arg0 = 45;
        int Arg1 = 5;
        int Arg2 = 11;
        verify_case(4, Arg2, calc(Arg0, Arg1));
    }
    void test_case_5() {
        int Arg0 = 100;
        int Arg1 = 100;
        int Arg2 = 8;
        verify_case(5, Arg2, calc(Arg0, Arg1));
    }

// END CUT HERE

};


//BEGIN CUT HERE
//int main() {
//    CartInSupermarketEasy ___test;
//    ___test.run_test(-1);
//
//}
//END CUT HERE
