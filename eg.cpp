#include<bits/stdc++.h>
using namespace std;
int search(const vector<int> &A, int B) {
    int n=A.size()-1;
    int lo=0,hi=n;int indx=n;
   // cout<<A[n]<<"\n";
    while(lo<=hi){
        int mid=(lo+hi)/2;
       // cout<<"hi= "<<hi<<"lo= "<<lo<<"mid= "<<mid<<"\n";
       // cout<<"A[mid]= "<<A[mid]<<"\n";
        if(A[mid]>=A[n]){indx=mid;lo=mid+1;}
        else hi=mid-1;
    }
   // cout<<"INDX= "<<indx<<"\n";
    int ans=-1;
    if(A[indx]>=B && A[0]<=B){
        int low=0,hih=indx;
        while(low<=hih){
            int mid=(low+hih)/2;
           // cout<<"hi= "<<hih<<"low= "<<low<<"mid= "<<mid<<"A[mid]= "<<A[mid]<<"\n";
            if(A[mid]>B){hih=mid-1;}
            else if(A[mid]==B){ans=mid;break;}
            else low=mid+1;
        }
    }
    else{
        int low=indx+1,hih=n;
        while(low<=hih){
            int mid=(low+hih)/2;
            if(A[mid]>B){hih=mid-1;}
            else if(A[mid]==B){ans=mid;break;}
            else low=mid+1;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
int main(){
	int n;cin>>n;
	vector<int>A;
	for(int i=0;i<n;i++){int x;cin>>x;A.push_back(x);}
	int B;cin>>B;
	search(A,B);
	return 0;	
}
