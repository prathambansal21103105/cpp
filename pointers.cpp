#include<iostream>
using namespace std;
int main(){
    int t;
    cout<<&t<<endl;
    float f=10.72;
    float* pf=&f;   // for storing an addresss we need to put a '*'
    double d=122.32;
    double* pd =&d;
    cout<<*pf<<endl;
    cout<<pd<<endl;
    cout<<sizeof(pf)<<endl;
    return 0;
} 