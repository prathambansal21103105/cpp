#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int ncr(int n,int r){
    int ncr=factorial(n)/(factorial(r)*factorial(n-r));
    return ncr;
}

//pascal's triangle

int main(){
    int rows;
    cout<<"Give no. of rows---"<<endl;
    cin>>rows;
    cout<<"Pascal's Triangle--"<<endl;
    for(int i=1;i<=rows;i++){
        int k=i;
        for(int j=0;j<k;j++){
            cout<<ncr(k-1,j)<<" ";
        }
        cout<<endl;
    }

    return 0;
}
