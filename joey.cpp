#include<iostream> 
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;

        vector<int>v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        long long ans=1;
        for(int i=0;i<n;i++){
            ans=ans*v[i];
        }
        ans=ans+n-1;
        ans*=2022;
        cout<<ans<<endl;

        t-=1;
    }
}