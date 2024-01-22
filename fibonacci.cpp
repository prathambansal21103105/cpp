#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    return 0;
}
// Extended-
// 1. Base Case- Prove f(0) or f(1) is true
// 2. IH- Assume f(i) is true for all i<=k
// 3. IS- Use 2. to Prove f(k+1) is true