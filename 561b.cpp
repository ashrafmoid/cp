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
  int k;cin>>k;
  int n=-1,m=-1;
  for(int i=5;i*i<=k;i++){
    if(k%i==0 && k/i >=5){n=i;m=k/i;break;}
  }
  if(n==-1){cout<<"-1\n";return 0;}
  char st[5];st[0]='a';st[1]='e';st[2]='i';st[3]='o';st[4]='u';
  queue<int> q;
  for(int i=0;i<5;i++)q.push(i);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){cout<<st[q.front()];int z=q.front();q.pop();q.push(z);}
    //for(int j=5;j<m;j++)cout<<'t';
  //  cout<<"\n";
    int z=q.front();q.pop();q.push(z);
  }
  return 0;
}
