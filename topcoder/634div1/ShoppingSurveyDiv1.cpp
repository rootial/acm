/*BEGINCUT

 ENDCUT */
#line 5 "ShoppingSurveyDiv1.cpp"

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

class ShoppingSurveyDiv1 {
public:

    int minValue(int N, int K, vector <int> s) {
        for(int r = 0; r <= N; r++) {
            vector<int> x = s;

            for(int &y:x)
                y = max(0, y-r);
            int mx = *max_element(x.begin(), x.end());
            int sum = accumulate(x.begin(), x.end(), 0);
            if(sum <= (N-r)*(K-1) && mx <= N-r) return r;
        }
        return N;
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
        int Arg0 = 10;
        int Arg1 = 2;
        int Arr2[] = {1, 2, 3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 0;
        verify_case(0, Arg3, minValue(Arg0, Arg1, Arg2));
    }
    void test_case_1() {
        int Arg0 = 5;
        int Arg1 = 2;
        int Arr2[] = {1, 2, 3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 1;
        verify_case(1, Arg3, minValue(Arg0, Arg1, Arg2));
    }
    void test_case_2() {
        int Arg0 = 4;
        int Arg1 = 4;
        int Arr2[] = {4, 4, 4, 2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 2;
        verify_case(2, Arg3, minValue(Arg0, Arg1, Arg2));
    }
    void test_case_3() {
        int Arg0 = 20;
        int Arg1 = 3;
        int Arr2[] = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 10;
        verify_case(3, Arg3, minValue(Arg0, Arg1, Arg2));
    }
    void test_case_4() {
        int Arg0 = 4;
        int Arg1 = 2;
        int Arr2[] = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 2;
        verify_case(4, Arg3, minValue(Arg0, Arg1, Arg2));
    }
    void test_case_5() {
        int Arg0 = 2;
        int Arg1 = 3;
        int Arr2[] = {1, 1, 1, 2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 1;
        verify_case(5, Arg3, minValue(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};


//// BEGIN CUT HERE
//int main() {
//    ShoppingSurveyDiv1 ___test;
//    ___test.run_test(-1);
//
//}
//// END CUT HERE

