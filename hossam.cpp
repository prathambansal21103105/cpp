Copy
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        long long n;
        cin>>n;
 
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int a=v[0];
        int b=v[n-1];
        if(a==b){
            long long ans=n*(n-1);
            cout<<ans<<endl;
        }
        else{
            long long count1=0;
            long long count2=0;
            for(int i=0;i<n;i++){
                if(v[i]==a){
                    count1+=1;
                }
                if(v[i]==b){
                    count2+=1;
                }
            }
            long long ans=count1*count2*2;
            cout<<ans<<endl;
        }
        t-=1;
    }
    return 0;
}