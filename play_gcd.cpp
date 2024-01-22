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
        vector<int>vnew;
        for(int i=0;i<v.size()-1;i++){
            int x=__algo_gcd(v[i],v[i+1]);
            int y=(v[i]*v[i+1])/x;
            vnew.push_back(y);
        }
        vnew.push_back(v.back());
        int flag=0;
        for(int i=0;i<vnew.size()-1;i++){
            int x=__algo_gcd(vnew[i],vnew[i+1]);
            if(x!=v[i+1]){
                flag=1;
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