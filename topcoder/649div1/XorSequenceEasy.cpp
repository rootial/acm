
#line 3 "XorSequenceEasy.cpp"

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


class XorSequenceEasy {
public:
    int getmax(vector <int> A, int N) {
        int ans = 0, B = 0;
        int n = sz(A);
        N = __builtin_popcount(N-1);
//        cout << N << endl;
        for(int i = 0; i < N; i++) {
            int tmp[2];
            tmp[0] = tmp[1] = 0;
            for(int k = 0; k < n; k++)
                for(int l = k+1; l < n; l++) {
                    if(((A[k]^A[l])>=(1<<i)) &&
                            ((A[k]^A[l])<(1<<(i+1))))
                        tmp[(A[k]>>i)&1]++;
                }
            if(tmp[0] < tmp[1]) B |= (1<<i);
        }
//        bug(1)
        for(int i = 0; i < n; i++) A[i] ^= B;
        for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++)
                ans += (A[i] < A[j]);
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
        int Arr0[] = {3,2,1,0,3,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 4;
        int Arg2 = 8;
        verify_case(0, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_1() {
        int Arr0[] = {3,0,4,6,1,5,7,6};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 8;
        int Arg2 = 21;
        verify_case(1, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_2() {
        int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 16;
        int Arg2 = 76;
        verify_case(2, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_3() {
        int Arr0[] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 8;
        int Arg2 = 0;
        verify_case(3, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_4() {
        int Arr0[] = {408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295
                      ,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108
                      ,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169
                      ,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484
                      ,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667
                     };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1073741824;
        int Arg2 = 720;
        verify_case(4, Arg2, getmax(Arg0, Arg1));
    }

// END CUT HERE

};


//BEGIN CUT HERE
//int main() {
//    XorSequenceEasy ___test;
//    ___test.run_test(-1);
//    return 0;
//}
//END CUT HERE
