#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int LEN = 1000;
const int MAXV = 10000;
const int vLEN = 4;

int n,ans,a[233];

class BigInt {
    short l,a[LEN];
    void format() {
        while (l>=1&&a[l-1]==0) --l;
    }
public:
    BigInt(long long x=0) {
        l=0;
        memset(a,0,sizeof a);
        do {
            a[l++]=x%MAXV;
            x/=MAXV;
        } while (x);
    }
    BigInt(const char * s) {
        memset(a,0,sizeof a);
        int len=strlen(s);
        l=(len+vLEN-1)/vLEN;
        int p=l-1,j=0;
        if (len%vLEN!=0) {
            for (int i=0; i<len%vLEN; ++i)
                a[p]=a[p]*10+s[j++]-'0';
            --p;
        }
        while (p>=0) {
            for (int i=0; i<vLEN; ++i)
                a[p]=a[p]*10+s[j++]-'0';
            --p;
        }
    }
    BigInt operator + (const BigInt &o) const {
        BigInt x;
        x.l=max(l,o.l);
        int jin=0;
        for (int i=0; i<x.l; ++i) {
            x.a[i]=a[i]+o.a[i]+jin;
            jin=x.a[i]/MAXV;
            x.a[i]%=MAXV;

        }
        if (jin) x.a[x.l++]=jin;
        x.format();
        return x;
    }
    BigInt operator * (const BigInt &o) const {
        BigInt x;
        x.l=l+o.l;
        int jin=0;
        for (int i=0; i<l; ++i) {
            jin=0;
            for (int j=0; j<o.l; ++j) {
                x.a[i+j]=x.a[i+j]+a[i]*o.a[j]+jin;
                jin=x.a[i+j]/MAXV;
                x.a[i+j]%=MAXV;
            }
            x.a[i+o.l]=jin;
        }
        x.format();
        return x;
    }
    void output() {
        printf("%d",a[l-1]);
        for (int i=l-2; i>=0; --i) {
            int tmp=MAXV/10;
            while (tmp>1) {
                if (a[i]<tmp) putchar('0');
                tmp/=10;
            }
            printf("%d",a[i]);
        }
    }
} C[233][233],f[233];

void divide(int l,int r,vector<int> &vec) {
    int sz=r-l+1;
    ans+=r-l;
    if (sz==1) a[l]=vec[0];
    else {
        vector<int> vec1,vec2;
        vec1.push_back(vec[sz-2]);
        vec2.push_back(vec[sz-1]);
        int mid=(l+r)>>1;
        for (int i=l; i<mid; ++i) vec1.push_back(vec[i-l]);
        for (int i=mid; i<r-1; ++i) vec2.push_back(vec[i-l]);
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        divide(l,mid,vec1);
        divide(mid+1,r,vec2);
    }
}

void init() {
    C[0][0]=C[1][0]=C[1][1]=BigInt(1ll);
    for (int i=2; i<=200; ++i) {
        C[i][0]=C[i][i]=BigInt(1ll);
        for (int j=1; j<i; ++j)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    f[1]=BigInt(1ll);
    for (int i=2; i<=200; ++i) {
        f[i]=f[(i+1)/2]*f[i-(i+1)/2];
        f[i]=f[i]*C[i-2][(i+1)/2-1];
        f[i]=f[i]+f[i];
    }
}

int main() {
//    freopen("merge.in","r",stdin);
//    freopen("merge.out","w",stdout);
    init();
    scanf("%d",&n);
    vector<int> vec;
    for (int i=1; i<=n; ++i) vec.push_back(i);
    divide(1,n,vec);
    printf("%d\n",ans);
    for (int i=1; i<=n; ++i) printf("%d%c",a[i],i==n?'\n':' ');
    f[n].output();
    return 0;
}
