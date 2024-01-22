#include<iostream>  //here we use the middle element to find a number
using namespace std;
int binarysearch(int input[],int n,int val){
    int start=0;
    int end=n-1;
    int mid;
    bool a=true;
    int ans;
    while(a){
        mid=(start+end)/2;
        if (input[mid]==val){
            ans=mid;
            a=false;
        }
        else{
            if (input[mid]>val){
                end=mid-1;
                if (input[end]<val or input[start]>val){
                    ans=-1;
                    a=false;
                }
            }
            else{
                start=mid+1;
                if(input[start]>val or input[end]<val){
                    ans=-1;
                    a=false;
                }
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int t;
    cin>>t;
    int x;
    int arr2[t];
    for(int i=0;i<t;i++){
        cin>>arr2[i];

    }
    for(int i=0;i<t;i++){
        int x=arr2[i];
        int start=0;
        int end=n-1;
        int ans=binarysearch(arr1,n,x);
        cout<<ans<<endl;
    }
    return 0;
}