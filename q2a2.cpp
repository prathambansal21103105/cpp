#include<iostream>
using namespace std;
void bubblesort(int v[], int size){
    int count=0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            count++;
            if(v[j]>v[j+1]){
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    cout<<"No. of comparisons: "<<count<<endl;
}
int main(){
    int arr[]={18,56,27,7,8,4,9,31,81,1};
    int size=10;
    cout<<"Pratham Bansal"<<endl;
    cout<<"SID-2110105"<<endl;
    bubblesort(arr, size);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}