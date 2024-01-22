#include<iostream> //here we use the middle element to find a number
using namespace std;
int binarysearch(int arr1[],int x,int start,int end){
    int mid=int((start+end)/2);
    if (arr1[mid]==x){
        return mid;
    }
    else{
        if (x>arr1[mid]){
            start=mid+1;
            if(x<arr1[start] or x>arr1[end]){
                return -1;
            }
            return binarysearch(arr1,x,start,end);
        }
        else{
            end=mid-1;
            if(x<arr1[start] or x>arr1[end]){
                return -1;
            }
            return binarysearch(arr1,x,start,end);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int input1[n];
    for(int i=0;i<n;i++){
        cin>>input1[i];
    }
    int x;
    cin>>x;
    int start=0;
    int end=n-1;
    int ans=binarysearch(input1,x,0,n-1);
    cout<<ans<<endl;
    return 0;
}