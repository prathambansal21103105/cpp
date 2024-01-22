#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x;
        cin>>x;
        if(x<=100){
            cout<<x<<endl;
        }
        else if(x>100 and x<=1000){
            cout<<x-25<<endl;
        }
        else if(x>1000 and x<=5000){
            cout<<x-100<<endl;
        }
        else if(x>5000){
            cout<<x-500<<endl;
        }
        t-=1;
    }
    return 0;
} 