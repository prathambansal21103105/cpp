#include<iostream>
using namespace std;

int fibodp(int n){
    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n+1;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int fibomemo(int n, int* arr){
    if(n==0 or n==1){
        return n;
    }
    else{
        if(arr[n]!=-1){
            return arr[n];
        }
        else{
            int retval=fibomemo(n-1,arr)+fibomemo(n-2,arr);
            arr[n]=retval;
            return retval;
        }
    }
}
int fibohelper(int n){
    int* arr=new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    return fibomemo(n,arr);
}

int fibo(int n){
    if(n==0 or n==1){
        return n;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

int main(){
    int n;
    cin>>n;
    int ans1=fibodp(n);
    int ans2=fibohelper(n);
    int ans3=fibo(n);
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    return 0;
}