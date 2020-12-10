// http://acm.hdu.edu.cn/submit.php?pid=1950
#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+5;
int T, p, a[maxn], d[maxn]; // f[i] 长度为 i 的最长上升子序列的结尾的值（最小）
int ans,len;
int bs(int t) {
    int l=1,r=len,m;
    while(l<r) {
        m=(l+r)>>1;
        if(d[m]>=t) {
            r=m;
        } else {
            l=m+1;
        }
    }
    return l;
}
int solve() {
    d[1] = a[1];
    len=1;
    for(int i=2;i<=p;++i) {
        if(a[i]>d[len]) {
            d[++len]=a[i];
        } else {
            int po=bs(a[i]);
            d[po]=min(d[po], a[i]);
        }
    }
    return len;
}
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&p);
        for(int i=1;i<=p;++i) scanf("%d", &a[i]);
        ans=solve();
        printf("%d\n",ans);
    }
}
