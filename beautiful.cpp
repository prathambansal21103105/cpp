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
        int flag=0;
        int same=0;
        int sum=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            if(sum==v[i]){
                flag=1;
            }
            if(v[i]!=v[0]){
                same=1;
            }
            sum+=v[i];
        }
        
        if(flag==0){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            t-=1;
            continue;
        }
        if(same==0){
            cout<<"NO"<<endl;
            t-=1;
            continue;
        }
        
        vector<int>vnew;
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
            vnew.push_back(v[i]);
        }
        
        int j=0;
        int k=0;
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            if((i&1)==0){
                cout<<vnew[j]<<" ";
                j+=1;
            }
            else{
                cout<<v[k]<<" ";
                k+=1;
            }
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}