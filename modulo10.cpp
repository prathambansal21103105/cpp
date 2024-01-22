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

        long long max1=-1;
        vector<long long>v;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            v.push_back(x);
        }

        for(int i=0;i<n;i++){
            if(v[i]%10==5){
                v[i]=v[i]+5;
            }
            else if(v[i]%10==0){
                continue;
            }
            else{
                while(v[i]%10!=2){
                    v[i]=v[i]+(v[i]%10);
                }
            }
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(v[i]!=v[0]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                if(v[i]%10==0){
                    continue;
                }
                v[i]=v[i]%20;
            }
            int check=0;
            for(int i=0;i<n;i++){
                if(v[i]!=v[0]){
                    check=1;
                    break;
                }
            }
            if(check==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        t-=1;
    }
    return 0;
}

/*
22 22 26
no
1 2 4 9
16 16 16 18
no
*/