#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sumodd=0;
    int sumeven=0;
    while (n>0){
        int lastdigit=n%10;
        if (lastdigit%2==0){
            sumeven+=lastdigit;
        }
        else{
            sumodd+=lastdigit;
        }
        n=n/10;
    }
    cout<<sumeven<<" "<<sumodd<<endl;
    return 0;
}