#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    int arr1[100000];
    int ans=1;
    for (int i=0;i<100000;i++){
        ans*=2;
        ans=ans%1000000007;
        arr1[i]=ans;
    }
    while (t>0){
        int n;
        cin>>n;
        cout<<arr1[n-2]<<endl;
        t-=1;
    }    
    return 0;
}