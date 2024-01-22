#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    int smallOutput=factorial(n-1);
    int output=n*smallOutput;
    return output;
}

int main(){
    cout<<factorial(4)<<endl;
    return 0;
}
// PMI
// 1. Base case f(0),f(1) is true
// 2. Induction Hypothesis - assume f(k) is true
// 3. Induction Step - using step 2 prove that f(k+1) is true
