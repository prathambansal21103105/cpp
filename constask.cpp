#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        int n;
        cin>>n;
        if(n==3){
            cout<<"NO"<<endl;
        }
        else if(n&1){
            int y=(n-1)/2;
            int x=1-y;
            for(int i=0;i<n;i++){
                if(i&1){
                    cout<<y<<" ";
                }
                else{
                    cout<<x<<" ";
                }
            }
            cout<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                if(i==n-1){
                    cout<<2<<endl;
                }
                else if(i&1){
                    cout<<2<<" ";
                }
                else{
                    cout<<-2<<" ";
                }
            }
        }

        t-=1;
    }
    return 0;
}

/*
-1 2 -1 2 -1
-2 3 -2 3 -2 3 -2
-3 4 -3 4 -3 4 -3 4 -3

*/