#include<iostream> // here we start comparring and swapping the first two pairs and we get max element at last after every round
using namespace std;
void bubblesort(int input[],int size){
    int size1=size;
    int n=size-1;
    while(n>0){
        for(int j=0;j<size1-1;j++){
            if (input[j+1]<input[j]){
                int temp=input[j];
                input[j]=input[j+1];
                input[j+1]=temp;
            }
            else{
                continue;
            }
        }
        size1-=1;
        n-=1;
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
    bubblesort(arr,n);
    return 0;
}