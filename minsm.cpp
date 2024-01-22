#include<iostream>
#include<algorithm>
long long int gcd1(long long int a,long long int b) {
   if(b==0){
    return a;
   }
   else if(a==0){
    return b;
   }
   else if(a>b){
    return gcd1(b,a%b);
   }
   else{
    return gcd1(a,b%a);
   }
}
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        long long int n;
        cin>>n;
        long long int a[n];
        for(long long int i=0;i<n;i++){
            long long int b;
            cin>>b;
            a[i]=b;
        }
        long long int min=1000000000;
        for(long long int i=0;i<n-1;i++){
            long long int gcd=gcd1(a[i],a[i+1]);
            if(gcd<min){
                min=gcd;
            }
        }
        long long int ans=min*n;
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}