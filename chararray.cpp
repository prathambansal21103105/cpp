#include<iostream>
using namespace std;
int length(char input[]){
    int count=0;
    int i=0;
    while(input[i]!='\0'){
        count+=1;
        i+=1;
    }
    return count;
}
int main(){
    int n=100;
    char b[100];
    cin>>b;
    cout<<b<<endl;
    cout<<length(b)<<endl;
    return 0;
}
// whenever we give an input char it only stores value till the space If we enter first name space last name it will only store till first name in the array.