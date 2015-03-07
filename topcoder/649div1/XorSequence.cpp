
#line 3 "XorSequence.cpp"

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define lowbit(x) ((x)&(-(x)))
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
const int maxn = 131072 + 10;

int order[maxn], A[maxn];
LL ma[33][2];
LL res[maxn][2];
int cnt;

bool cmp(const int &x, const int &y) {
    return A[x] < A[y];
}

class XorSequence {
public:

    void add(int x, int v) {
        while(x < maxn) {
            if(res[x][1] != cnt) {
                res[x][0] = 0;
                res[x][1] = cnt;
            }
            res[x][0] += v;
            x += lowbit(x);
        }
    }
    LL query(int x) {
        LL ans = 0;
        while(x > 0) {
            if(res[x][1] != cnt){
                res[x][0] = 0;
                res[x][1] = cnt;
            }
            ans += res[x][0];
            x -= lowbit(x);
        }
        return ans;
    }
    void dfs(int l, int r, int dep) {
        if(l > r || dep < 0) return;
        int mid = l-1;
        while(mid+1 <= r) {
            if(!(A[order[mid+1]]&(1<<dep)))
                mid++;
            else break;
        }

        if(mid >= l && mid < r) {
            cnt++;
            //memset(res[dep], 0, sizeof(res[dep]));
            for(int i = l; i <= mid; i++)
                add(order[i], 1);
            for(int i = mid+1; i <= r; i++) {
                ma[dep][0] += query(order[i]);
            }
            // memset(res[dep], 0, sizeof(res[dep]));
            cnt++;
            for(int i = mid+1; i <= r; i++)
                add(order[i], 1);
            for(int i = l; i <= mid; i++)
                ma[dep][1] += query(order[i]);
        }
        dfs(l, mid, dep-1);
        dfs(mid+1, r, dep-1);
    }
    long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R) {
        A[1] = A0;
        A[2] = A1;
        for (int i = 3; i <= sz; i++) {
            A[i] = (1LL*A[i - 2] * P%N + 1LL*A[i - 1] * Q%N + R) % N;
        }
        int n = __builtin_popcount(N-1);
//        for(int i = 1; i <= sz; i++)
//            printf("%d ", A[i]);
//        cout << endl;

        for(int i = 1; i <= sz; i++)
            order[i] = i;
        sort(order + 1, order + sz + 1, cmp);
        cnt = 0;
        memset(ma, 0, sizeof ma);
        memset(res, 0, sizeof res);

        dfs(1, sz, n-1);
        LL ans = 0;
        for(int i = 0; i < n; i++)
            ans += max(ma[i][0], ma[i][1]);
        TL
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
    void verify_case(int Case, const long long &Expected, const long long &Received) {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0() {
        int Arg0 = 4;
        int Arg1 = 6;
        int Arg2 = 3;
        int Arg3 = 2;
        int Arg4 = 0;
        int Arg5 = 1;
        int Arg6 = 3;
        long long Arg7 = 8LL;
        verify_case(0, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
    }
    void test_case_1() {
        int Arg0 = 8;
        int Arg1 = 8;
        int Arg2 = 2;
        int Arg3 = 5;
        int Arg4 = 3;
        int Arg5 = 1;
        int Arg6 = 4;
        long long Arg7 = 13LL;
        verify_case(1, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
    }
    void test_case_2() {
        int Arg0 = 8;
        int Arg1 = 7;
        int Arg2 = 3;
        int Arg3 = 0;
        int Arg4 = 1;
        int Arg5 = 2;
        int Arg6 = 4;
        long long Arg7 = 12LL;
        verify_case(2, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
    }
    void test_case_3() {
        int Arg0 = 32;
        int Arg1 = 15;
        int Arg2 = 7;
        int Arg3 = 9;
        int Arg4 = 11;
        int Arg5 = 2;
        int Arg6 = 1;
        long long Arg7 = 60LL;
        verify_case(3, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
    }
    void test_case_4() {
        int Arg0 = 131072;
        int Arg1 = 131072;
        int Arg2 = 7;
        int Arg3 = 7;
        int Arg4 = 1;
        int Arg5 = 0;
        int Arg6 = 0;
        long long Arg7 = 0LL;
        verify_case(4, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
    }
    void test_case_5() {
        int Arg0 = 131072;
        int Arg1 = 131070;
        int Arg2 = 411;
        int Arg3 = 415;
        int Arg4 = 398;
        int Arg5 = 463;
        int Arg6 = 9191;
        long long Arg7 = 4302679760LL;
        verify_case(5, Arg7, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6));
    }

// END CUT HERE

};


//BEGIN CUT HERE
//int main() {
////    bug(1)
//    XorSequence ___test;
//    ___test.run_test(-1);
//}
////END CUT HERE
