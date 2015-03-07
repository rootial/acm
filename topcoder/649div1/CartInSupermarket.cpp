
#line 3 "CartInSupermarket.cpp"

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

class CartInSupermarket {
public:
    int calcmin(vector <int> a, int b) {
        int low = 1, high = (int)1e9;
        while(low < high) {
            int mid = (low+high)/2;
            if(possible(a, mid, b)) high = mid;
            else low = mid+1;
        }
        return low;
    }
private:
    bool possible(vector<int> a, int timeLimit, int b) {
        LL sum = 0;
        for(int x: a) sum += numSplits(x, timeLimit);
        return sum <= b;
    }
    int numSplits(int x, int timeLimit) {
        int low = 0, high = x;
        while(low < high) {
            int mid = (low+high)/2;
            if(possible(x, mid, timeLimit)) high = mid;
            else low = mid + 1;
        }
        if(low == x) return (int)1e9 + 100;
        return low;
    }
    bool possible(LL x, LL numSplits, int timeLimit) {
        LL numParts = 1;
        int tl = 0;
        while(numParts <= numSplits){
            numSplits -= numParts;
            numParts *= 2;
            tl++;
        }
        x = max(0LL, x-(numParts-numSplits));
        return (tl + 1) + (x + numParts + numSplits - 1) / (numParts + numSplits) <= timeLimit;
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
        int Arr0[] = {8};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 3;
        int Arg2 = 4;
        verify_case(0, Arg2, calcmin(Arg0, Arg1));
    }
    void test_case_1() {
        int Arr0[] = {6,6,5};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 3;
        int Arg2 = 4;
        verify_case(1, Arg2, calcmin(Arg0, Arg1));
    }
    void test_case_2() {
        int Arr0[] = {611403868, 893083571, 145818284, 336882486, 856831904, 75804314};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 921631865;
        int Arg2 = 32;
        verify_case(2, Arg2, calcmin(Arg0, Arg1));
    }
    void test_case_3() {
        int Arr0[] = {15,20,11,13,18,24,25,21,22,10,15,14,19};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 0;
        int Arg2 = 25;
        verify_case(3, Arg2, calcmin(Arg0, Arg1));
    }
    void test_case_4() {
        int Arr0[] = {671122748,846444748,84701624,608579554,672060899,967957440,31438849,734849843,376589643,904285209
                      ,80693344,211737743,85405464,444633541,293184188,935462519,146753109,972886045,496631016,601669536
                      ,257574086,958464570,6294570,546189534,668105964,601197313,784337929,921840143,70408284,722040626
                      ,253400894,56411549,811940644,152086353,122638884,776352066,118932182,177589709,538122558,127914469
                      ,523761221,290027568,734517444,819458123,699130727,784698122,810265337,283326309,593596316,368671876
                     };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 6478;
        int Arg2 = 3805054;
        verify_case(4, Arg2, calcmin(Arg0, Arg1));
    }

// END CUT HERE

};


////BEGIN CUT HERE
//int main() {
//    CartInSupermarket ___test;
//    ___test.run_test(2);
//    return 0;
//}
////END CUT HERE
