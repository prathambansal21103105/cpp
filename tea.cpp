#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x,y,z;
        cin>>x>>y>>z;
        if (x<=y){
            cout<<z<<endl;
        }
        else{
            int div=(x/y);
            int sum=z*div;
            int rem=x-(div*y);
            if (rem==0){
                cout<<sum<<endl;
            }
            else{
                cout<<sum+z<<endl;
            }
        }
        t-=1;
    }
    return 0;
}