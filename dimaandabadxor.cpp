#include<bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int dp[1001];
int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;cin>>n;
    string s;
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++){cin>>s;mp[s]=1;}
    int q;cin>>q;
    string t;
    for(int i=0;i<q;i++){
        cin>>t;
        dp[0]=1;
        for(int j=1;j<=t.size();j++){
            dp[j]=0;
            for(int k=j;k>0;k--){
                string tmp=t.substr(k-1,j-k+1);
                dp[j]=dp[k-1]&&mp[tmp];
                if(dp[j])break;
            }
            //if(q==2){
              //  cout<<"dp= "<<dp[j]<<"\n";
            //}
        }
        if(dp[t.size()]){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}

