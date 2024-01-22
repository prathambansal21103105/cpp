#include<iostream>
using namespace std;
int arrayRotateCheck(int input[],int size){
    int count=1;
    for(int i=0;i<=size-1;i++){
        if (input[i+1]>=input[i]){
            count+=1;
        }
        else{
            break;
        }
    }
    if (size==0){
        return 0;
    }
    int flag=0;
    for(int i=0;i<size-1;i++){
        if (input[i]==input[i+1]){
            flag+=0;
        }
        else{
            flag+=1;
        }
    if(flag==0){
        return 0;
    }    
    if (count==size){
        return 0;
    }
    }
    return count;
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