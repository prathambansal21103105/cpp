#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x;
        cin>>x;
        if (x%3==0){
            cout<<0<<endl;
        }
        else{
            bool ans=true;
            int counter=0;
            while(ans){
                counter+=1;
                if ((x+counter)%3==0){
                    cout<<counter<<endl;
                    ans=false;
                    break;
                }
            }
        }
        t-=1;
    }
    return 0;
}