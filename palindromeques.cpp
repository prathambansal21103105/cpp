#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Give a no.:";
    cin>>n;
    int i;
    int palindrome=0;
    for(i=11;i<=n;i++){
        int reverse=0;
        int j=i;
        while(j>0){
            int lastdigit=j%10;
            reverse=reverse*10+lastdigit;
            j=j/10;
        }
        if (i==reverse){
            cout<<i<<endl;
            palindrome+=1;
        }
    }
    cout<<"No. of palindromes:"<<palindrome<<endl;
    return 0;
}