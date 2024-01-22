#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
        }
        else if(n==2){
            cout<<2<<" "<<1<<endl;
        }
        else{
            int max=n;
            int min=1;
            int count=0;
            while(count!=n){
                if(count%2==0){
                    cout<<max<<" ";
                    max-=1;
                    count+=1;
                }
                else{
                    cout<<min<<" ";
                    min+=1;
                    count+=1;
                }
            }
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}