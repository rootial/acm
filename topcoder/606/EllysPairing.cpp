#line 2 "EllysPairing.cpp"
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
class EllysPairing {
public:
    int getMax(int M, vector <int> cnt, vector <int> first, vector <int> mult, vector <int> add) {
        int val = -1, ct = 0;
        int n = (int)cnt.size();
        int m = 0;
        for (int i = 0; i < n; i++) {
            m += cnt[i];
            unsigned fi = first[i];
//                        cout << fi << ' ';

            if (!ct) {
                val = fi;
                ct = 1;
            } else {
                ct = val == (int)fi ? ct + 1 : ct - 1;
            }
            for (int j = 1; j < cnt[i]; j++) {
                fi = (fi * mult[i] + add[i])&(M-1);
//                            cout << fi << ' ';

                if (!ct) {
                    val = fi;
                    ct = 1;
                } else {
                    ct = val == (int)fi ? ct + 1 : ct - 1;
                }
            }
        }
//        bug(val)
        ct = 0;
        for (int i = 0; i < n; i++) {
            unsigned fi = first[i];
            ct += val == (int)fi;
            for (int j = 1; j < cnt[i]; j++) {
                fi = (fi * mult[i] + add[i])&(M-1);
//                  cout << fi << ' ';
                ct += val == (int)fi;
            }
        }
//        bug(val)
        if (ct > (m+1)/2) {
            return m/2-(ct-(m+1)/2);
        } else {
            return m/2;
        }
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
        int Arg0 = 16;
        int Arr1[] = {4, 7};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {5, 3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {2, 3};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {1, 0};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 5;
        verify_case(0, Arg5, getMax(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_1() {
        int Arg0 = 8;
        int Arr1[] = {6, 4, 3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0, 3, 2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {3, 7, 5};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {0, 3, 2};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 5;
        verify_case(1, Arg5, getMax(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_2() {
        int Arg0 = 128;
        int Arr1[] = {42, 13, 666, 17, 1337, 42, 1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {18, 76, 3, 122, 0, 11, 11};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {33, 17, 54, 90, 41, 122, 20};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {66, 15, 10, 121, 122, 1, 30};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 1059;
        verify_case(2, Arg5, getMax(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_3() {
        int Arg0 = 1048576;
        int Arr1[] = {4242, 42, 9872, 13, 666, 21983, 17, 1337, 42, 1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {19, 18, 76, 42, 3, 112, 0, 11, 11, 12};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {27, 33, 10, 8, 17, 9362, 90, 41, 122, 20};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {98, 101, 66, 15, 10, 144, 3, 1, 5, 1};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 16232;
        verify_case(3, Arg5, getMax(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_4() {
        int Arg0 = 1073741824;
        int Arr1[] = {894602, 946569, 887230, 856152, 962583, 949356, 904847, 829100, 842183, 958440,
                      811081, 864078, 809209, 938727, 949135, 892809, 816528, 961237, 979142, 890922
                     };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {844085078, 898937259, 243490172, 887804102, 187696417, 156820442, 237600210, 618812924, 153000239, 912364033,
                      254936966, 650298774, 982988140, 649258331, 566444626, 201481721, 492943390, 1061953081, 492672963, 960519711
                     };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1036482037, 583219072, 819168094, 253755052, 548208982, 401830167, 638626082, 43642932, 123607749, 485521178,
                      860368129, 30334704, 219771462, 733375600, 130839219, 415503960, 294132484, 1044831462, 256910484, 198852170
                     };
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {889169006, 604831366, 967292994, 980686280, 844875791, 1027687492, 357734882, 295879743, 48284748, 421729100,
                      1049536313, 327207332, 948053446, 271229570, 664579359, 795815285, 842856528, 876662975, 675611938, 634229925
                     };
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 8971965;
        verify_case(4, Arg5, getMax(Arg0, Arg1, Arg2, Arg3, Arg4));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    EllysPairing ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
