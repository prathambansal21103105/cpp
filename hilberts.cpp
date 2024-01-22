#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t>0){
        int n;
        cin>>n;

        vector<long long>v;
        vector<long long>vnew;


        for(int i=0;i<n;i++){
            long long a;
            cin>>a;
            v.push_back(a);
        }
        for(int k=0;k<n;k++){
            vnew.push_back(k+v[k%n]);
        }
        int flag=0;
        for(int i=0;i<n-1;i++){
            long long curr=vnew[i];
            for(int j=i+1;j<n;j++){
                if((vnew[j]-curr)%n==0){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        t-=1;
    }
    return 0;
}