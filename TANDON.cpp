#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll cache[8][1000001]
map<pair<ll,ll>,ll>mp;
ll modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    while (x < 0) 
       x += m0; 
  
    return x; 
} 
ll raise_pwr(ll base,ll pwr,ll mod){
	if(pwr==0)return 1ll;
	if(pwr==1)return base;
	ll tmp=raise_pwr(base,pwr/2,mod)%mod;
	if(pwr%2)return (((tmp*base)%mod)*tmp)%mod;
	return (tmp*tmp)%mod;
}
ll rvrse(ll num){
	ll res=0;
	while(num){
		res=res*10ll+num%10;
		num=num/10;
	}
	return res;
}
ll nkm(ll k,ll m,ll mod){
	if(m==0){
		if(k==0)return 1ll;
		return 0ll;
	}
	if(m==2){
		ll res=0ll;
		for(int i=0;i<10;i++)for(int j=0;j<10;j++){
			if((i-j+28)%7==k)res++;
		}
		return res;
	}
	//cout<<"k= "<<k<<"m= "<<m<<"\n";
	//if(m<1000001 && cache[k][m]!=-1)return cache[k][m];
	if(mp.find(make_pair(k,m))!=mp.end())return mp[make_pair(k,m)];
	ll res=0;
	int lmt=7;
	if(m%2)lmt=10;
	for(int i=0;i<lmt;i++){
		ll ksub,nsub;
		if(m%2){ksub=(k-1ll*i+14ll)%7ll;
			res+=nkm(ksub,m-1ll,mod);
			res%=mod;continue;
		}
		// else ksub=(k+1ll*i)%7ll;
		//while(ksub<0)ksub+=7ll;
		ksub=(k-1ll*i+14ll)%7ll;
		nsub=nkm(ksub,m/2,mod)*nkm(i%7ll,m/2,mod);nsub%=mod;
		//res+=nkm(ksub,m/2,mod);res%=mod;res+=nkm(i%7ll,m-m/2,mod);res%=mod;
		res+=nsub;
		res%=mod;
	}
	//if(m<1000001)cache[k][m]=res;
	mp[make_pair(k,m)]=res;
	//cout<<"m= "<<m<<"res= "<<res<<"\n";
	return res;
}
int main(){
	int t;cin>>t;
	ll mod=1e9+7;
	//for(int i=0;i<7;i++)for(int j=0;j<1000001;j++)cache[i][j]=-1ll;
	while(t--){
		ll n,k;cin>>n>>k;
		ll ans=0;
		if(k==1){
			cout<<raise_pwr(10,n,mod)<<"\n";
			continue;
		}
		if(k==2){
			if(n<2){cout<<"5\n";continue;}
			ll pwr=raise_pwr(10,n-1,mod)-1ll;
			//ll pwr=raise_pwr(10,min(n,4ll),mod)-1ll;
			while(pwr<0)pwr+=mod;
			if(pwr>=mod) pwr%=mod;
			ll invrse=modInverse(9ll,mod)%mod;
			ans=(((20ll*pwr)%mod)*invrse+5ll)%mod;
			cout<<ans<<"\n";
			continue;
		}
		else if(k==3 || k==9){
			ll pwr=raise_pwr(10,n,mod)-1ll;
			if(pwr<0)pwr+=mod;
			else pwr%=mod;
			ll invrse=modInverse(k,mod)%mod;
			ll ans=(pwr*invrse+1ll)%mod;
			cout<<ans<<"\n";
			continue;
		}
		else if(k==4){
			ll sml=0;
			ll pwr=raise_pwr(10,min(n,3ll),mod)-1ll;
			while(pwr<0)pwr+=mod;
			pwr%=mod;
			for(int i=0;i<=pwr;i+=4){
				ll nwnum=rvrse(i);
				if(nwnum%4==0)sml++;
			}
			if(n<=3){cout<<sml<<"\n";continue;}
			ans+=sml;
			pwr=raise_pwr(10,n-3ll,mod)-1ll;
			while(pwr<0)pwr+=mod;
			pwr%=mod;
			ll invrse=modInverse(9,mod)%mod;
			ll tmp=20ll*((25ll*pwr)%mod);tmp%=mod;
			tmp=tmp*invrse;tmp%=mod;
			ans=(ans+tmp)%mod;
			cout<<ans<<"\n";
			continue;
		}
		else if(k==5){
			if(n<2){cout<<"2\n";continue;}
			ll pwr=raise_pwr(10,n-1,mod)-1ll;
			while(pwr<0)pwr+=mod;
			pwr%=mod;
			ll invrse=modInverse(9,mod)%mod;
			ans=(2ll*((pwr*invrse)%mod)+2ll)%mod;
			cout<<ans<<"\n";
			continue;
		}
		else if(k==6){
			if(n<3){
				ll pwr=raise_pwr(10,n,mod);
				ll cnt=0;
				//cout<<"2\n";continue;
				for(int i=0;i<pwr;i+=6){
					ll tmp=rvrse(i);
					if(tmp%6==0){cnt++;}
				}
				cout<<cnt<<"\n";
				continue;
			}
			ll pwr=raise_pwr(10,n-1,mod)-1ll;
			while(pwr<0)pwr+=mod;
			pwr%=mod;
			ll invrse=modInverse(9,mod)%mod;
			pwr=(pwr*invrse)%mod;
			pwr-=(n-1ll);
			while(pwr<0)pwr+=mod;
			//invrse=modInverse(3,mod)%mod;
			pwr=(pwr*3ll)%mod;
			invrse=modInverse(9,mod)%mod;
			pwr=(pwr*invrse)%mod;
			ans=((20ll*pwr)%mod + 2ll +6ll*(n-1ll))%mod;
			cout<<ans<<"\n";
			continue;
		}
		else if(k==8){
			ll sml=0;
			ll pwr=raise_pwr(10,min(n,5ll),mod)-1ll;
			while(pwr<0)pwr+=mod;
			pwr%=mod;
			for(int i=0;i<=pwr;i+=8){
				ll nwnum=rvrse(i);
				if(nwnum%8==0)sml++;
			}
			if(n<6){cout<<sml<<"\n";continue;}
			ans+=sml;
			pwr=raise_pwr(10,n-5,mod)-1ll;
			while(pwr<0)pwr+=mod;
			pwr%=mod;
			ll invrse=modInverse(9,mod)%mod;
			ll tmp=(pwr*invrse)%mod;tmp=((tmp*125ll)%mod)*100ll;
			tmp%=mod;
			ans=(ans+tmp)%mod;
			cout<<ans<<"\n";
			continue;	
		}
		else if(k==7){
			ll Nx=(n+2ll)/3,Ny=(n+1ll)/3,Nz=n/3;
			for(int i=0;i<7;i++){
				ll y=(7-i)%7;
				ll z=i;
				ll nx=nkm(i,Nx,mod)%mod;
				ll ny=nkm(y,Ny,mod)%mod;
				ll nz=nkm(z,Nz,mod)%mod;

				nx=(nx*ny)%mod;
				nx=(nx*nz)%mod;
				ans=(ans+nx)%mod;
				//ans+=(nx*ny*nz)%mod;
				//ans=ans%mod;
			}
			cout<<ans%mod<<"\n";
		}
		else cout<<"1\n";
	}
	return 0;
}