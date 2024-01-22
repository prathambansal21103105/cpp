#include<iostream>
using namespace std;

void selectionsort(int arr[], int size){
    int count=0;
    int iter=0;
    for(int i=0;i<size-1;i++){
        int minel=arr[i];
        int mindex=i;
        for(int j=i+1;j<size;j++){
            count++;
            if(arr[j]<minel){
                mindex=j;
                minel=arr[j];
            }
        }
        int temp=arr[i];
        arr[i]=arr[mindex];
        arr[mindex]=temp;
        iter++;
    }
    cout<<"No. of iterations: "<<iter<<endl;
    cout<<"No. of comparisons: "<<count<<endl;

}
int main(){
    int arr[]={18,56,27,7,8,4,9,31,81,1};
    int size=10;
    cout<<"Pratham Bansal"<<endl;
    cout<<"SID-2110105"<<endl;
    selectionsort(arr,size);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}