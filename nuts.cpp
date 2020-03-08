#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,a,b,v;cin>>k>>a>>b>>v;
    int ans=0;
    while(a>0){
        int z=min(k-1,b);
        b-=z;
        z++;
        a-=v*z;
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
