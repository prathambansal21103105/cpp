#include<iostream> //here we find the min element and keep on swapping it with the initial elements
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int min;
    for(int i=0;i<n;i++){
        min=arr[i];
        for(int j=i+1;j<n;j++){
            if (arr[j]<min){
                int temp=min;
                arr[i]=arr[j];
                min=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}