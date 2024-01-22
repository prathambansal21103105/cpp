#include<iostream>
using namespace std;
int arrayRotateCheck(int input[],int n){
    int count=1;
    for(int i=0;i<n-1;i++){
        if(input[i]>input[i+1]){
            return count;
        }
        count+=1;
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        int ans=arrayRotateCheck(input,n);
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}