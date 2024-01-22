#include<iostream>
using namespace std;
int main(){
    // constant int
    const int i=20; //once we create a const integer we can't change its value further in the code
    cout<<i<<endl;

    int const i2=10; //we can write const int or int const no change 
    cout<<i2<<endl;    

    // constant reference from a non const int
    int j=12;
    const int & k=j;
    j++;
    //k++;here we can't do k++ because it is const the path of k is const so we can't change through k but change through j is allowed and will be equally reflected in k but the only thing is that the change can't be made through k
    cout<<k<<endl;

    // constant reference from a const int
    int const j2=12;
    int const& k2=j2;
    //j2++;  here both can't be changed because both the paths are constant
    //k2++;
    
    // reference from a const int
    int const j3=123;
    //int& k3=j3; this case not possible 

    return 0;
}