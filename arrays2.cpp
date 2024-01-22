#include<iostream>
using namespace std;
void printarray(int input[],int n){
    for(int i=0;i<n;i++){
        cout<<input[i]<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    printarray(ar,n);
    return 0;
}
// when we are passing an array in a function it only passses the address of the zeroth element so there is no way for the function to know the size of that array so we need to explicitly pass the size of the array
// address is always stored as a hexadecimal so address is always a double and it has 8 bytes
// so size of an address is always 8 bytes