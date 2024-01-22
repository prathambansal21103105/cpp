#include<iostream>
using namespace std;
int findSecondLargest(int *input, int n)
{
    int max;
    max=input[0];
    for(int i=0;i<n;i++){
        if (input[i]>max){
            max=input[i];
            int temp=input[0];
            input[0]=input[i];
            input[i]=temp;
        }
    }
    int flag=0;
    int max1;
    max1=input[1];
    for(int i=1;i<n;i++){
        if (input[i]>max1 and input[i]!=max){
            input[1]=input[i];
            max1=input[i];
            flag=1;
        }
    }
    if (flag==0){
        return -2147483648;
    }
    else{
        return max1;
    }
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
        int ans;
        ans=findSecondLargest(input,n);
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}