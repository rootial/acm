#line 2 "Mutalisk.cpp"
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
int dp[22][220][500];

class Mutalisk {
public:
    int minimalAttacks(vector <int> x) {
        int n = (int)x.size();
        memset(dp, 0x0f, sizeof dp);
        for (int i = 0; i < 220; i++)
            for (int j = 0; j < 500; j++)
                dp[0][i][j] = 0;
        int sum = 0;
        int n1 = 0, n2 = 0;
        for (int i = 1; i <= n; n1 += (x[i-1]+8)/9, n2 += (x[i-1]+2)/3, sum += x[i-1], i++) {
            for (int j = 0; j <= n1; j++)
                for (int k = 0; k <= n2; k++) {
                    for (int l = 0; l <= (x[i-1]+8)/9; l++)
                        for (int m = 0; m <= (max(0, x[i-1]-l*9)+2)/3; m++) {
                            if (j+l < 220 && k+m < 500)
                                dp[i][j+l][k+m] = min(dp[i-1][j][k]+max(0, x[i-1]-l*9-m*3), dp[i][j+l][k+m]);
                        }
                }
        }
        int ans = inf;
        for (int i = 0; i < 220 ; i++)
            for (int j = 0; j < 500; j++) {
                if (n != 1)
                ans = min(ans, max(max(dp[n][i][j], i), j));
                else ans = min(ans, dp[n][i][j] + i + j);
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
        int Arr0[] = {12,10,4};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2;
        verify_case(0, Arg1, minimalAttacks(Arg0));
    }
    void test_case_1() {
        int Arr0[] = {54,18,6};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 6;
        verify_case(1, Arg1, minimalAttacks(Arg0));
    }
    void test_case_2() {
        int Arr0[] = {1,1,1,1,1,1,1,1,1,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 4;
        verify_case(2, Arg1, minimalAttacks(Arg0));
    }
    void test_case_3() {
        int Arr0[] = {55,60,53};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 13;
        verify_case(3, Arg1, minimalAttacks(Arg0));
    }
    void test_case_4() {
        int Arr0[] = {60};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 7;
        verify_case(4, Arg1, minimalAttacks(Arg0));
    }
    void test_case_5() {
        int Arr0[] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 93;
        verify_case(5, Arg1, minimalAttacks(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Mutalisk ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
