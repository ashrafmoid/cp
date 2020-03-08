#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
vector<int> z(100005);
void z_function(string s) {
    int n = (int) s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    //return z;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;cin>>s;
	int len=s.size();
	vector<int>v(len);
	for(int i=0;i<len;i++){
		if(s[i]=='a')v[i]=1;
		else v[i]=0;
		if(i){v[i]+=v[i-1];}
	}
	if(v[len-1]==len){cout<<s<<"\n";return 0;}
	int lwr=lower_bound(v.begin(),v.end(),v[len-1])-v.begin();
	//cout<<lwr<<"\n";
	int flg=-1;
	for(int i=lwr;i<len;i++){
		//cout<<" i= "<<i <<"v1= "<<(i+1-v[i])<<"v2= "<<((len-i-1))<<"\n";
		if(i+1-v[i]==(len-i-1)){flg=i;break;}
	}
	//cout<<"flg= "<<flg<<"\n";
	if(flg==-1){cout<<":(";return 0;}
	int ans=-1;int j=flg+1;
	string t="";int i;
	for( i=0;i<=flg && j<len ;){
		t+=s[i];
		if(s[i]=='a'){i++;continue;}
		if(s[i]==s[j]){;j++;i++;ans=j;}
		else {
			ans=-1;
			break;
		}
	}
	while(i<=flg && s[i]=='a'){t+=s[i];i++;}
	//cout<<"j= "<<j<<"i= "<<i<<"\n";
	if(j==len && i>flg){cout<<t<<"\n";}
	else cout<<":(";
	return 0;
}