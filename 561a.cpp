#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
ll  mod=1e9+7;
const int maxn=1e5+5;
int freq[30];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;string s;

  for(int i=0;i<n;i++){cin>>s;
    freq[s[0]-'a']++;
  }
  int ans=0;
  for(int i=0;i<26;i++){
    int tmp=freq[i]/2;
    freq[i]-=tmp;
  //  if(tmp>freq)tmp--;
    //else freq[i]--;
    ans+=(freq[i]*(freq[i]-1))+(tmp*(tmp-1));
  }
  cout<<(ans/2);
  return 0;
}
