#include<iostream>
using namespace std;
int main(){
    int i=10;
    int& j=i; //declaring refrence variable
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    int k=100;    //its like saying 2 bando ke same naam hai chahe i kaho ya fir j kaho
    j=k;
    cout<<j<<endl;
    cout<<i<<endl;
    return 0;
}