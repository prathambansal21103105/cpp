#include<iostream>
using namespace std;
int pairSum(int arr[],int n,int num){
    int ans=0;
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int rest=num-arr[i];
        for(int j=0;j<n;j++){
            if(rest==arr[j] and j!=i){
                ans+=1;
            }
        }
    }
    return ans/2;
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
    int num;
    cin>>num;
    int ans=pairSum(input,n,num);
    cout<<ans<<endl;
    t-=1;
    }
    return 0;
}