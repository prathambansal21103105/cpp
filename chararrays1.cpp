#include<iostream>
using namespace std;
int main(){
    char input[100];
    cin.getline(input,100);
    cout<<input<<endl;
    return 0;
}
// cin.getline(string_name,len) reads the string till a new line is reached
// so when we use this function we can use space.
// it only reads len-1 characters as it takes the last character as null or '\0'.