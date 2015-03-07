
#line 3 "SumOfArrays.cpp"

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

const int maxn = (int)2e5 + 10;
const int LOW = 10;

int cntA[maxn], cntB[maxn];
int A[maxn], B[maxn], C[maxn];
bitset<maxn> a, b;

struct Complex {
    double x, y;
    Complex() {}
    Complex(double x, double y):x(x), y(y) {}
};
Complex operator + (const Complex &a, const Complex &b) {
    Complex c;
    c.x = a.x+b.x;
    c.y = a.y+b.y;
    return c;
}
Complex operator - (const Complex &a, const Complex &b) {
    Complex c;
    c.x = a.x-b.x;
    c.y = a.y-b.y;
    return c;
}
Complex operator * (const Complex &a, const Complex &b) {
    Complex c;
    c.x = a.x*b.x-a.y*b.y;
    c.y = a.x*b.y+a.y*b.x;
    return c;
}

inline void FFT(vector<Complex> &a, bool inverse) {
    int n = a.size();
    for(int i = 0, j = 0; i < n; i++) {
        if(j > i)
            swap(a[i], a[j]);
        int k = n;
        while(j & (k>>=1)) j &= ~k;
        j |= k;
    }
    double PI = inverse ? -pi : pi;
    for(int step = 2; step <= n; step <<= 1) {
        double alpha = 2*PI/step;
        Complex wn(cos(alpha), sin(alpha));
        for(int k = 0; k < n; k += step) {
            Complex w(1, 0);
            for(int Ek = k; Ek < k+step/2; Ek++) {
                int Ok = Ek + step/2;
                Complex u = a[Ek];


                Complex t = a[Ok]*w;
                a[Ok] = u-t;
                a[Ek] = u+t;
                w = w*wn;
            }
        }
    }
    if(inverse)
        for(int i = 0; i < n; i++)
            a[i].x = (a[i].x/n);
}
vector<int> operator * (const bitset<maxn> &v1, const bitset<maxn> &v2) {
    int S1 = v1.size(), S2 = v2.size();
    int S = 2;
    while(S < S1+S2) S <<= 1;
    vector<Complex> a(S), b(S);
    for(int i = 0; i < S; i++)
        a[i].x = a[i].y = b[i].x = b[i].y = 0.0;
    for(int i = 0; i < S1; i++)
        a[i].x = v1[i];
    for(int i = 0; i < S2; i++)
        b[i].x = v2[i];
    FFT(a, false);
    FFT(b, false);
    for(int i = 0; i < S; i++)
        a[i] = a[i] * b[i];
    FFT(a, true);
    vector<int> res(maxn, 0);
    for(int i = 0; i < maxn; i++)
        res[i] = round(a[i].x);
    return res;
}

class SumOfArrays {
public:
    void gen(int A[], vector<int> seed, int n) {
        A[0] = seed[0];
        A[1] = seed[1];
        for(int i = 2; i < n; i++)
            A[i] = (1LL * A[i-1] * seed[2] + 1LL* A[i-2] * seed[3] + seed[4]) % seed[5];
//        for(int i = 0; i < n; i++)
//            printf("%d ", A[i]);
//        puts("");
    }
    char ans[100];

    string findbestpair(int n, vector <int> Aseed, vector <int> Bseed) {
        gen(A, Aseed, n);
        gen(B, Bseed, n);
//        memset(cntA, 0, sizeof cntA);
        memset(cntB, 0, sizeof cntB);
        memset(C, 0, sizeof C);

        for(int i = 0; i < n; i++) {
            cntA[A[i]]++;
            cntB[B[i]]++;
        }

        vector<int> bigA, bigB;
        for(int i = 0; i < maxn; i++) {
            if(cntA[i] >= LOW)
                bigA.pb(i);
            if(cntB[i] >= LOW)
                bigB.pb(i);
        }

        for(int p: bigA) for(int q: bigB) {
                C[p+q] += min(cntA[p], cntB[q]) - LOW + 1;
            }
        vector<int> c(maxn);
        for(int k = 1; k < 10; k++) {
            a.reset();
            b.reset();
            for(int i = 0; i < maxn; i++) {
                if(cntA[i] >= k)
                    a[i] = 1;
                if(cntB[i] >= k)
                    b[i] = 1;
            }

            c = a*b;
            for(int i = 0; i < maxn; i++)
                C[i] += c[i];
//            for(int i = 1; i <= 4; i++)
//            cout << C[i] << ' ';
//            cout << endl;
        }

        int X = -1, Y = 0;
        for(int i = 0; i < maxn; i++)
            if(C[i] >= X) {
                X = C[i];
                Y = i;
            }

        sprintf(ans, "%d %d", X, Y);
//        TL
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
        int Arg0 = 3;
        int Arr1[] = {1,1,1,1,1,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,1,1,1,1,2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "3 2";
        verify_case(0, Arg3, findbestpair(Arg0, Arg1, Arg2));
    }
    void test_case_1() {
        int Arg0 = 3;
        int Arr1[] = {1,1,1,1,1,4};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,1,1,1,1,4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "2 4";
        verify_case(1, Arg3, findbestpair(Arg0, Arg1, Arg2));
    }
    void test_case_2() {
        int Arg0 = 3;
        int Arr1[] = {1,2,0,0,1,5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0,1,0,0,1,5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "3 2";
        verify_case(2, Arg3, findbestpair(Arg0, Arg1, Arg2));
    }
    void test_case_3() {
        int Arg0 = 14;
        int Arr1[] = {5,6,2,4,6,11};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {6,5,2,4,2,7};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "9 7";
        verify_case(3, Arg3, findbestpair(Arg0, Arg1, Arg2));
    }
    void test_case_4() {
        int Arg0 = 100000;
        int Arr1[] = {6274,99908,61138,86540,56297,100000};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {28275,25494,65423,61118,64925,100000};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "3027 102148";
        verify_case(4, Arg3, findbestpair(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};


// BEGIN CUT HERE
int main() {
    SumOfArrays ___test;
    ___test.run_test(-1 );

}
// END CUT HERE
