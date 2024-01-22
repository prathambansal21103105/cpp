#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t>0){
        int l,r;
        cin>>l>>r;
        if (l%2==0){
            cout<<l<<" "<<l+1<<" "<<l+2<<" "<<l+3<<endl;
        }
        else if(l+4<=r){
            cout<<l+1<<" "<<l+2<<" "<<l+3<<" "<<l+4<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        t-=1;
    }
    return 0;
}

// for xor operator consecutive even-odd pair always gives 1