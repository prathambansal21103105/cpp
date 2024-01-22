#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t>0){
        int n;
        cin>>n;
        int input[n];
        int total=0;
        int input1[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
            input1[i]=input[i];
            if (i>=1){
                total=total*input[i];
            }
        }
        for(int i=0;i<n;i++){
            if (i>0){
                int ans=input[i]^total;
                input[i]=ans;
            }
        }
        for(int i=0;i<n;i++){
            if (input[i]==input[0]){
                cout<<input1[i];
            }
        }
        t-=1;
    }
    return 0;
}