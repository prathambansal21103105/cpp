#include<iostream>
using namespace std;
int increment(int a){
    a=a+1;
    return a;
}
int main(){
    int n=10;
    n=increment(n);
    cout<<n<<endl;
    return 0;
}