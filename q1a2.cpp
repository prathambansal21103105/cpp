#include<iostream>
#include<climits>
using namespace std;

int binarysearch1(int arr[], int st, int en, int tar, int val){
    if(st<=en){
        int mid=(st+en)/2;
        if(arr[mid]==tar){
            val=mid;
            return binarysearch1(arr,st,mid-1,tar,val);
        }
        else if(arr[mid]>tar){
            return binarysearch1(arr,st,mid-1,tar,val);
        }
        else{
            return binarysearch1(arr,mid+1,en,tar,val);
        }
    }
    else{
        return val;
    }
}
int binarysearch2(int arr[], int st, int en, int tar, int val){
    if(st<=en){
        int mid=(st+en)/2;
        if(arr[mid]==tar){
            val=mid;
            return binarysearch2(arr,mid+1,en,tar,val);
        }
        else if(arr[mid]>tar){
            return binarysearch2(arr,st,mid-1,tar,val);
        }
        else{
            return binarysearch2(arr,mid+1,en,tar,val);
        }
    }
    else{
        return val;
    }
}

int main(){
    int arr[]={1,4,7,7,8,9,18,27,31,56,81};
    int size=11;
    int st=0;
    int en=10;
    cout<<"Pratham Bansal"<<endl;
    cout<<"SID-2110105"<<endl;
    int ans1=binarysearch1(arr,0,10,1,INT_MAX);
    int ans2=binarysearch2(arr,0,10,1,INT_MIN);
    if(ans1==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        for(int i=ans1;i<=ans2;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    ans1=binarysearch1(arr,0,10,81,INT_MAX);
    ans2=binarysearch2(arr,0,10,81,INT_MIN);
    if(ans1==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        for(int i=ans1;i<=ans2;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    ans1=binarysearch1(arr,0,10,7,INT_MAX);
    ans2=binarysearch2(arr,0,10,7,INT_MIN);
    if(ans1==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        for(int i=ans1;i<=ans2;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    ans1=binarysearch1(arr,0,10,3,INT_MAX);
    ans2=binarysearch2(arr,0,10,3,INT_MIN);
    if(ans1==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        for(int i=ans1;i<=ans2;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}