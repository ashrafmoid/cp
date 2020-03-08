// #include<cstdio>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;
const int N=(int)(3e3);
int n,a[N],b[N],c[N],f[N][2];

int main() {
    //freopen("in.txt","r",stdin);
    scanf("%d",&n) ;
        for(int i=0; i<n; ++i) {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; ++i) {
            scanf("%d",&b[i]);
        }
        for(int i=0; i<n; ++i) {
            scanf("%d",&c[i]);
        }
        f[0][0]=a[0];
        f[0][1]=-99999;
        for(int i=1; i<n; ++i) {
            f[i][0]=f[i][1]=0;
            f[i][0]=std::max(f[i][0],a[i]+f[i-1][0]-a[i-1]+b[i-1]);
            f[i][1]=std::max(f[i][1],b[i]+f[i-1][0]);
            //if(i-1) {
                f[i][0]=std::max(f[i][0],a[i]+f[i-1][1]-b[i-1]+c[i-1]);
                f[i][1]=std::max(f[i][1],b[i]+f[i-1][1]);
           // }
        }
        printf("%d\n",std::max(f[n-1][0],f[n-1][1]));
   // }
    return 0;
}