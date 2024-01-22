#include<iostream>
using namespace std;
int binarySearch(int input[],int n,int val){
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    while(low<=high){
        if (input[mid]==val){
            return mid;
        }
        else if (input[mid]<val){
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int t;
    cin>>t;
    while(t>0){
        int x;
        cin>>x;
        int ans;
        ans=binarySearch(input,n,x);
        t-=1;
    }
    return 0;
}