#include<iostream>
using namespace std;
void insertionsort(int v[], int size){
    int count=0;
    for(int i=1;i<size;i++){
        int j=i-1;
        count++;
        while(j>=0 and v[j]>v[j+1]){
            count++;
            int temp = v[j];
            v[j] = v[j+1];
            v[j+1]=temp;
            j--;
        }
    }
    cout<<"No. of comparisons: "<<count<<endl;
}

int main(){
    int arr[]={18,56,27,7,8,4,9,31,81,1};
    int size=10;
    cout<<"Pratham Bansal"<<endl;
    cout<<"SID-2110105"<<endl;
    insertionsort(arr,size);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}