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
vector<int> len;

class PeriodicJumping {
public:
    int minimalTime(int x, vector <int> jump) {
        LL tmp = 0;
        for(int y: jump)
            tmp += 2*y;
        x = abs(x);
        if(x == 0) return 0;
        int n = jump.size();
        int ans = 1LL*((x-1)/tmp)*n*2;
       LL a = 0, b = (x-1)/tmp*tmp;
		
        while(1) {
            for(int y:jump) {
                
                if(a > y) {
                    a = a-y;
                } else if(y <= b) {
                    a = 0;
                } else {
                    a = y-b;
                }
                b+=y;
                ans++;
                if(x >= a && x <= b)
                    break;
            }
            if(x >= a && x <= b)
                break;
        }
        return ans;
    }
};
