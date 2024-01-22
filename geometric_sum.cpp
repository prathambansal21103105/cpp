#include<iostream>
#include<cmath>
using namespace std;
double geometricSum(int k){
    if(k==0){
        return 1;
    }
    else{
        double n=1/(pow(2,k));
        return n+geometricSum(k-1);
    }
}
int main(){
    int k;
    cin>>k;
    cout<<geometricSum(k)<<endl;
    return 0;
}