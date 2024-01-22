#include<iostream> // here we compare the 1st index with the starting index and shift it with zeroth index if it is small and further check other indexes.
using namespace std;
void insertionsort(int input[],int size){
    for(int i=1;i<size;i++){
        for(int j=i-1;j>=0;j--){
            if (input[i]<input[j]){
                int temp=input[i];
                input[i]=input[j];
                input[j]=temp;
                i-=1;
            }
            else{
                break;
            }
        }
    }
    for(int i=0;i<size;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionsort(arr,n);
    return 0;
}