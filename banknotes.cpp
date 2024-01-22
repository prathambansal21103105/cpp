#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int n;
        cin>>n;

        long k;
        cin>>k;
        k+=1;

        vector<long>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(pow(10,x));
        }

        long ans=0;
        for(int i=0;i<n;i++){
            if(k<=0){
                break;
            }
            if(i==n-1){
                ans+=k*v[i];
                k-=k;
                break;
            }
            int x=v[i+1]/v[i];
            x-=1;
            if(x<=k){
                ans+=x*v[i];
                k-=x;
            }
            else{
                ans+=k*v[i];
                k-=k;
            }
        }
        cout<<ans<<endl;

        t-=1;
    }
    return 0;
}