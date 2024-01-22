#include<iostream>
using namespace std;
int binarySearch(int input[],int size,int element){
    int mid=0;
    if(size%2==0){
        mid=(size/2)-1;
    }
    else{
        mid=size/2;
    }
    if(input[mid]==element){
        return mid;
    }
    else if(size==0){
        return -1;
    }
    else{
        if(element>input[mid]){
            int ans=binarySearch(input+mid+1,size-mid-1,element);
            if(ans>=0){
                return mid+1+ans;
            }
            else{
                return -1;
            }
        }
        else{
            int ans=binarySearch(input,mid,element);
            if(ans>=0){
                return ans;
            }
            else{
                return -1;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int x;
    cin>>x;
    int ans=binarySearch(input,n,x);
    cout<<ans<<endl;
    return 0;
}