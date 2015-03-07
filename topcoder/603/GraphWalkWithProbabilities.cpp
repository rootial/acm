
#line 3 "GraphWalkWithProbabilities.cpp"

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
const int maxn = 3000 + 10;
double dp[55][maxn];

class GraphWalkWithProbabilities {
public:
    vector<int> win, lose;
    vector<int> g[55];

    double dfs(int node, int steps) {
        double &res = dp[node][steps];
        if(!(res < 0)) return res;
        res = 0;
        for(int to: g[node])
            res = max(res, win[to]/100.0 + (100-win[to]-lose[to])/100.0*dfs(to, steps-1));
        return res;
    }
    double findprob(vector <string> graph, vector <int> winprob, vector <int> loseprob, int Start) {
        for(int i = 0; i < 55; i++) for(int j = 0; j < maxn; j++)
            dp[i][j] = -1.0;
//        bug(1)
        for(int i = 0; i < 55; i++) dp[i][0] = 0.0;
        win = winprob;
        lose = loseprob;
//        bug(1)
        int n = sz(graph);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                if(graph[i][j] == '1')
                g[i].pb(j);
        }
        dfs(Start, maxn-1);
        return dp[Start][maxn-1];
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
    void verify_case(int Case, const double &Expected, const double &Received) {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0() {
        string Arr0[] = {"1"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 0;
        double Arg4 = 0.5;
        verify_case(0, Arg4, findprob(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1() {
        string Arr0[] = {"11","11"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {60,40};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {40,60};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 0;
        double Arg4 = 0.6;
        verify_case(1, Arg4, findprob(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2() {
        string Arr0[] = {"11","11"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {3,4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 0;
        double Arg4 = 0.4285714285714286;
        verify_case(2, Arg4, findprob(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3() {
        string Arr0[] = {"110","011","001"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,1,10};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {20,20,10};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 0;
        double Arg4 = 0.405;
        verify_case(3, Arg4, findprob(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4() {
        string Arr0[] = {"111","111","011"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {100,1,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0,50,50};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 2;
        double Arg4 = 0.5;
        verify_case(4, Arg4, findprob(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    GraphWalkWithProbabilities ___test;
    ___test.run_test(-1);
}
// END CUT HERE
